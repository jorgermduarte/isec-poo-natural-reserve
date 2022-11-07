# poo-natural-reserve
POO-2022/2023

objetivo: Simulador de uma reserva natural povoada por diversos animais.

Metas:
    1 - 27 Novembro
        - ui reserva
        - estrutura animal
        - estrutura reserva
        - estrutura alimento
        - leitura do ficheiro de comandos (contantes.txt)
        - leitura de comandos e validações
        - implementações de comandos obrigatorioas:
          - ver animais e alimentos, deslizar a área visível para o lado/cima/abaixo, executar comandos em ficheiro (que são também validados), e terminar.
    2 - 8 de janeiro

projeto:
    - na inicialização do projeto algumas propriedades dos animais estão presentes num ficheiro de configuração
      - constantes.txt
    - O histórico de alimentos não pode usar coleções da STL (Biblioteca standard C++). Tudo o resto do histórico pode usar as classes STL que quiser mas o conjunto das entradas no histórico é implementado pelo aluno sem o auxílio de coleções.

comandos (consola): ( SIMULADOR)
    - interação do utilizador com a reserva natural
    - o utilizador pode efetuar ordens alterando o que acontece na reserva
    - comandos para avançar na simulação
    - comando para iteração / dia seguinte
    - lista de comandos a implementar presenta no pdf
    
ui: 
    - display da reserva e conteudo
    - area que apresenta a reserva
      - zona limitada e area limitada
        - comandos de setas teclado para movimentar na area apresentada
    - elementos representados por letras
    - zona no ecra para ver detalhes animais
    - zona no ecra destinada a leitura de comandos não interferindo com as outras duas.
    - As consequências visíveis dos seus comandos devem ser imediatamente
    representados visualmente, excepto se se reportarem a uma área da reserva que não esteja visível

reserva:
    - plano (matriz)
      - tamanho livre de 16 até 500
      - espaço finito sem fronteiras ( extremidade volta para o outro lado( como se fosse um globo))
    - animais
      - handle da posição no plano a nossa escolha
    - alimentos
      - handle da posição no plano a nossa escolha
    - ID static partilhado na criação de animais e alimentos
      - static field incremental partilhado por ambas as classes/estruturas
    - a reserva representa um terreno com diversas coisas que nela existem, e portanto, tudo o que existir na reserva partilh os acontecimentos gerais que ocorrem à reserva como um todo

animais: ( abstract class)
    - comportamento autonomo
    - comportamento variado
    - deslocam-se pela reserva
    - nascimento
    - morte
    - movimento ( regras especificas)
    - alimentação
      - alimentados por ordem especifica do utilizador
      - procurar e alimentar-se por iniciativa propria
    - interação com o meio ambiente
    - caracteristicas
      - peso (saudaveis ou nao)
      - reprodução
      - agressividade
      - duração de vida
      - saude (hp)
      - nome de especie
      - quantidade de fome (fome)
      - tem percepções e reage e interage com objetos e outros animais

especies de animais: (ver especificacoes no pdf) (derivam da classe animal ( herança ))
    - coelho
    - ovelha
    - lobo
    - canguru
    - animal misterio
      - o que quisermos ( um T-REX sem pernas)

alimentos: ( classe abstrata ou nao )
    - podem ser consumidos
    - valor nutritivo
    - toxicidade
    - cheiros ( mais de um )
    - gestao de tempo (duração de vida)


tipos de alimentos:
    - relva
    - cenoura
    - corpo
    - bife
    - alimento-misterio


libraria do professor:
    - objetivo de agilizar o processo de display da reserva


questoes:
    - sendo necessário posicionar o cursor em linha coluna? isto não será enviar a linha coluna? em vez de posicionar o cursor?
    - não existirão menus!? é só comandos e pronto?
    - zona no ecra destinada a leitura de comandos não interferindo com as outras duas?
      - como assim? tecnicamente a inserção de um comando pode alterar o estado do jogo( posições dos animais)
    - Os valores NL e NC são conhecidos apenas em runtime? como assim? é pedido através do simulador? é alteravel durante execução?
    - quando alguem morre passa a alimento corpo?

