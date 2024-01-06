#ifndef HISTORY_H

#define HISTORY_H
#include <stdbool.h>
#include <stddef.h>
#define DEFAULT_STACK_MAX_SIZE 10
#define SPLITTER_ARRAY_SIZE 6

typedef float SplitterPositionState;

typedef struct
{
    // layout position
    SplitterPositionState splitter_pos[SPLITTER_ARRAY_SIZE];
} State;

static State* undo_stack[DEFAULT_STACK_MAX_SIZE];
static State* redo_stack[DEFAULT_STACK_MAX_SIZE];
static State* current_state = NULL;

static int undo_stack_top     = 0;
static int undo_stack_bottom  = 0;
static int redo_stack_top     = 0;
static int redo_stack_bottom  = 0;

bool   undo_is_empty();
bool   redo_is_empty();
bool   undo_is_full();
bool   redo_is_full();
void   clear_redo_stack();
State* pop_from_undo_stack();
State* pop_from_redo_stack();
void   push_to_undo_stack(State* new_state);
void   push_to_redo_stack(State* new_state);

//extern void set_stack_max_size(int maxSize);

// Get the default stack max size of both undo and redo stack
extern int get_stack_max_size();
// Pop the state from the undo_stack and return the state
extern void undo();
// Pop the state from the redo_stack and return the state
extern void redo();
// Update the current state and push the old state into undo stack
extern void set_current_state_push_old_to_undo(SplitterPositionState position_data[SPLITTER_ARRAY_SIZE]);
// Get current state
extern SplitterPositionState *get_current_state();
#endif
