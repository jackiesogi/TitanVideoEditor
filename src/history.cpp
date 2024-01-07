#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "history.hpp"

bool undo_is_empty()
{
    return undo_stack_top == undo_stack_bottom;
}

bool redo_is_empty()
{
    return redo_stack_top == redo_stack_bottom;
}

bool undo_is_full()
{
    return (undo_stack_top + 1) % DEFAULT_STACK_MAX_SIZE == undo_stack_bottom;
}

bool redo_is_full()
{
    return (redo_stack_top + 1) % DEFAULT_STACK_MAX_SIZE == redo_stack_bottom;
}

bool is_same_state(float position_data[5])
{
    for(int i = 0; i < SPLITTER_ARRAY_SIZE; i++)
    {
        if(current_state->splitter_pos[i] != position_data[i])  return false;
    }
	return true;
}

void clear_redo_stack()
{
    for (int i = 0; i < DEFAULT_STACK_MAX_SIZE; i++)
    {
        if(redo_stack[i] != NULL)
        {
            free(redo_stack[i]);
            redo_stack[i] = NULL;
        }
    }
    redo_stack_top = redo_stack_bottom = 0;
}

State* pop_from_undo_stack()
{
    if(undo_is_empty())  // stack is empty
    {
        fprintf(stderr, "Cannot go back..., the undo stack is empty.\n");
        return NULL;
    }
    else
    {
        if(undo_stack_top == 0)  // jump through index 0 to last index
        {
            undo_stack_top = DEFAULT_STACK_MAX_SIZE - 1;
            return undo_stack[0];
        }
        else  // normal condition
        {
            return undo_stack[undo_stack_top--];
        }
    }
}

State* pop_from_redo_stack()
{
    if(redo_is_empty())  // stack is empty
    {
        fprintf(stderr, "Cannot go forward..., the redo stack is empty.\n");
        return NULL;
    }
    else
    {
        if(redo_stack_top == 0)  // jump through index 0 to last index
        {
            redo_stack_top = DEFAULT_STACK_MAX_SIZE - 1;
            return redo_stack[0];
        }
        else  // normal condition
        {
            return redo_stack[redo_stack_top--];
        }
    }
}

int get_next_index(int index)
{
    return (index == DEFAULT_STACK_MAX_SIZE - 1) ? 0 : index + 1;
}

void push_to_undo_stack(State* new_state)
{
    /* Get the next index in the circular queue */
	int undo_stack_top_next    = get_next_index(undo_stack_top);
    int undo_stack_bottom_next = get_next_index(undo_stack_bottom);
    	
    if(undo_is_full())  // stack is full, add new state and delete oldest state
    {
        if(undo_stack[undo_stack_top_next] != NULL) {
            //free(undo_stack[undo_stack_top_next]->splitter_pos);
            free(undo_stack[undo_stack_top_next]);
            undo_stack[undo_stack_top_next] = NULL;
        }
    	if(undo_stack[undo_stack_bottom_next] != NULL) { 
            //free(undo_stack[undo_stack_bottom_next]->splitter_pos);
            free(undo_stack[undo_stack_bottom_next]);
            undo_stack[undo_stack_bottom_next] = NULL;
        }
        undo_stack_top    = undo_stack_top_next;  // move top to next index
        undo_stack_bottom = undo_stack_bottom_next;  // move bottom to next index
         
        undo_stack[undo_stack_top] = new_state;
    }
    else  // stack is't full, add new state
    {
        undo_stack_top = undo_stack_top_next;
        undo_stack[undo_stack_top] = new_state;
    }
}

void push_to_redo_stack(State* new_state)
{
	int redo_stack_top_next    = get_next_index(redo_stack_top);
    int redo_stack_bottom_next = get_next_index(redo_stack_bottom);
    	
    if(redo_is_full())  // stack is full, add new state and delete oldest state
    {
        if(redo_stack[redo_stack_top_next] != NULL) {
            //free(redo_stack[redo_stack_top_next]->splitter_pos);
            free(redo_stack[redo_stack_top_next]);
            redo_stack[redo_stack_top_next] = NULL;
        }
    	if(redo_stack[redo_stack_bottom_next] != NULL) {
            //free(redo_stack[redo_stack_bottom_next]->splitter_pos);
            free(redo_stack[redo_stack_bottom_next]);
            redo_stack[redo_stack_bottom_next] = NULL;
        }
        redo_stack_top    = redo_stack_top_next;  // move top to next index
        redo_stack_bottom = redo_stack_bottom_next;  // move bottom to next index
         
        redo_stack[redo_stack_top] = new_state;
    }
    else  // stack is't full, add new state
    {
        redo_stack_top = redo_stack_top_next;
        redo_stack[redo_stack_top] = new_state;
    }
}

//extern void set_stack_max_size(int maxSize);

// Get the default stack max size of both undo and redo stack
extern int get_stack_max_size();
// 注意：undo()和redo()僅只於轉換undo_stack, redo_stack, current_state的內容, 和外部資料沒有交互
// Pop the state from the undo_stack and return the state
extern void undo()
{
	State* temp;
	if((temp = pop_from_undo_stack()) == NULL)  return;
    
    State* record = (State*)calloc(1, sizeof(State));
	// copy the info of state
    for(int i = 0; i < SPLITTER_ARRAY_SIZE; i++)
    {
        record->splitter_pos[i] = current_state->splitter_pos[i];
    }
	push_to_redo_stack(record);
    for(int i = 0; i < SPLITTER_ARRAY_SIZE; i++)
    {
        current_state->splitter_pos[i] = temp->splitter_pos[i];
    }
}
// Pop the state from the redo_stack and return the state
extern void redo()
{
	State* temp;
	if((temp = pop_from_redo_stack()) == NULL)  return;
    
    State* record = (State*)calloc(1, sizeof(State));
	// copy the info of state
    for(int i = 0; i < SPLITTER_ARRAY_SIZE; i++)
    {
        record->splitter_pos[i] = current_state->splitter_pos[i];
    }
	push_to_undo_stack(record);
    for(int i = 0; i < SPLITTER_ARRAY_SIZE; i++)
    {
        current_state->splitter_pos[i] = temp->splitter_pos[i];
    }
}

// float SplitterPositionArray[5]
extern void set_current_state_push_old_to_undo(float position_data[5])
{
	if(current_state == NULL)
	{
		current_state = (State*)calloc(1, sizeof(State));
        for(int i = 0; i < SPLITTER_ARRAY_SIZE; i++)
        {
            current_state->splitter_pos[i] = position_data[i];
        }
		return;
	}
	if(is_same_state(position_data)) return;
	if(!redo_is_empty())
    {
        clear_redo_stack();
    }
	State* record = (State*)calloc(1, sizeof(State));
	// copy the info of state
    for(int i = 0; i < SPLITTER_ARRAY_SIZE; i++)
    {
        record->splitter_pos[i] = current_state->splitter_pos[i];
    }
	push_to_undo_stack(record);
    for(int i = 0; i < SPLITTER_ARRAY_SIZE; i++)
    {
        current_state->splitter_pos[i] = position_data[i];
    }
}
// Return the current_state
extern SplitterPositionState *get_current_state()
{
	return current_state->splitter_pos;
}

/*// Push current state into undo state
extern void save_status(int value)
{
	State* current_state = (State*)calloc(1, sizeof(State));
	current_state->value = value;
	push_to_undo_stack(current_state);
} */
