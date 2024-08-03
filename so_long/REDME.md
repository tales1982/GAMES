# so_long

Bem-vindo ao repositório do jogo so_long! Este é um jogo simples desenvolvido em C utilizando a biblioteca MiniLibX.

## Descrição

so_long é um jogo onde o objetivo é coletar todos os itens espalhados pelo mapa e chegar ao ponto de saída. O jogo foi desenvolvido como parte de um projeto na 42 School para praticar conceitos de programação em C e uso de bibliotecas gráficas.

## Requisitos

Para compilar e executar o jogo, você precisará de:

- Um compilador C (por exemplo, `gcc`)
- `make` instalado no seu sistema
- As bibliotecas `MiniLibX` e `libft` (incluídas no repositório)

## Instalação

Siga os passos abaixo para compilar e executar o jogo:

1. Clone o repositório:

   ```sh
   git clone https://github.com/tales1982/GAMES
   cd so_long
Compile o código fonte utilizando o Makefile:

sh
Copiar código
make
Execute o jogo:

sh
Copiar código
./so_long maps/map.ber
Estrutura do Projeto
O projeto está organizado da seguinte forma:

bash
Copiar código
/so_long
  /lib
    /libft
    /minilibx-linux
  /maps
    map.ber
  /src
    close_window.c
    copy_image_part.c
    draw_exit.c
    draw_map.c
    free_resources.c
    key_event.c
    key_event_player.c
    load_map.c
    start_game.c
  Makefile
  so_long.c
  so_long.h
Uso
O jogo é controlado através do teclado:

Use as setas do teclado para mover o personagem.
Colete todos os itens para destravar a saída.
Chegue ao ponto de saída para vencer o jogo.
Funções Principais
Inicialização: initialize_game_window, start_game
Desenho do Mapa: draw_map, draw_exit
Leitura do Mapa: load_map, read_map_file, parse_line_to_map
Eventos de Teclado: key_event, handle_exit, update_position_and_image
Recursos e Imagens: load_image, initialize_images, free_resources, free_mlx_resources, free_images, free_map
Contribuição
Contribuições são bem-vindas! Sinta-se à vontade para abrir issues ou enviar pull requests. Para grandes mudanças, por favor, abra uma issue primeiro para discutir o que você gostaria de mudar.

Faça um fork do projeto
Crie um branch para sua feature (git checkout -b feature/nova-feature)
Commit suas mudanças (git commit -am 'Adiciona nova feature')
Envie para o branch (git push origin feature/nova-feature)
Abra um Pull Request

Obrigado por jogar so_long!
