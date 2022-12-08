

# Project meta 2 - implementations needed

- [ ] implement the base commands
  - [ ] exec_command_feedid
  - [ ] exec_command_feed
  - [ ] exec_command_killid
  - [ ] exec_command_kill
  - [ ] exec_command_nofood
  - [ ] exec_command_empty
  - [ ] exec_command_see
- [x] after the implementation of the base commands above we need to implement the command:
  - [x] exec_command_animal
  - [x] exec_command_food
- [ ] create a way to store all the commands executed by the user
  - [ ] create a way to store the commands in a list called on the Command.cpp (execute function)
    - [ ] remember that all the commands are based on the BaseCommand (easier)
      - [ ] implement the exec_command_store and exec_command_restore commands
- [x] remove all the mock animals from the code initialization
- [x] create  command testing files with different environments
  - [x] multiple animals at the same line column
  - [x] different types of foods 
  - [x] different types of animals
- [ ] do a project global check
- [ ] verify the animals/foods properties and correct if necessary
- [ ] implement the S and V handling types for all the animals and foods( not sure if the foods needs it) (constantes.txt)
- [ ] have a meeting to decide the main functions necessary to the animals interactions
- [ ] implement the main functions necessary to the animals interactions
- [ ] implement the "daily" function inside the execute_command_n
- [ ] finish the execute_command_n command
- [ ] global check of the project