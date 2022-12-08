

# Project meta 2 - implementations needed

- [ ] implement the base commands
  - [x] exec_command_nofood
  - [x] exec_command_feed
  - [x] exec_command_feedid
  - [x] exec_command_see
  - [ ] exec_command_killid
  - [ ] exec_command_kill
  - [ ] exec_command_empty
- [x] after the implementation of the base commands above we need to implement the command:
  - [x] exec_command_animal
  - [x] exec_command_food
- [x] remove all the mock animals from the code initialization
  - [x] create  command testing files with different environments
    - [x] multiple animals at the same line column
    - [x] different types of foods
    - [x] different types of animals
- [ ] do a project global check
- [ ] implement the S and V handling types for all the animals and foods( not sure if the foods needs it) (constantes.txt)
  - [x] S Types
  - [ ] V Types
- [ ] create a way to store all the commands executed by the user
  - [ ] create a way to store the commands in a list called on the Command.cpp (execute function)
    - [ ] remember that all the commands are based on the BaseCommand (easier)
      - [ ] implement the exec_command_store
      - [ ] implement the exec_command_restore command

- [ ] verify the animals/foods properties and correct if necessary
- [ ] have a meeting to decide the main functions necessary to the animals interactions
- [ ] implement the main functions necessary to the animals interactions
- [ ] implement the "daily" function inside the execute_command_n
- [ ] finish the execute_command_n command
- [ ] global check of the project