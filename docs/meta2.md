

# Project meta 2 - implementations needed

- [x] implement the base commands
  - [x] exec_command_nofood
  - [x] exec_command_feed
  - [x] exec_command_feedid
  - [x] exec_command_see
  - [x] exec_command_killid
  - [x] exec_command_kill
  - [x] exec_command_empty
- [x] after the implementation of the base commands above we need to implement the command:
  - [x] exec_command_animal
  - [x] exec_command_food
- [x] remove all the mock animals from the code initialization
  - [x] create  command testing files with different environments
    - [x] multiple animals at the same line column
    - [x] different types of foods
    - [x] different types of animals
- [X] implement the S and V handling types for all the animals and foods( not sure if the foods needs it) (constantes.txt)
  - [x] S Types
  - [X] V Types
- [x] create a way to store all the in-game memory reserve executed by the user
  - [x] implement the exec_command_store
  - [x] implement the exec_command_restore command
- [x] do a project global check
  - [ ] add validations on the commands that ask line/columns (check if the line/column is valid)
  - [ ] add validation for integers on the board size setup ( verify max size too )
  - [ ] verify if the kill command should invoke the body animal type on the location
  - [ ] do a change to the slide command ????? or not?
  - [ ] verify the animals/foods properties and correct if necessary
  - [ ] be aware / do a global checkup of the pointers/ memory to remove completely using the store/restore and kill commands
- [ ] have a meeting to decide the main functions necessary to the animals interactions
- [ ] implement the main functions necessary to the animals interactions
- [ ] implement the "daily" function inside the execute_command_n
- [ ] finish the execute_command_n command
- [ ] global check of the project