# Greenhouse

Este é um código desenvolvido para a automatização de uma estufa através do **Arduino**.

## Integrantes do Grupo
- Rafael Ames dos Santos
- Mikael Alexandre de Lucano
- Wesley Kauan Fritz

## Requisitos

Antes de começar, certifique-se de que você possui as ferramentas necessárias:

- **Arduino IDE**: Software open-source instalado
- **Arduino UNO**: Placa Uno R3 SMD CH340G + Cabo USB para Arduino
- **Módulo Relé Arduino**: 5V Dual-Channel Relay Module HW-383
- **Sensor de umidade do solo**: Capacitive Soil Moisture Sensor v1.2
- **Sensor de luminosidade**: BH1750 GY-302 Lux
- **Sensor de umidade e temperatura**: DHT11


# Configuração do Projeto

## 1. Clone o repositório:

Clone este repositório em sua máquina local com o seguinte comando:

git clone https://github.com/seu-usuario/n3Mobile.git
cd flutter_auth


## 2. Instale as dependências:
Após clonar o repositório, instale as dependências do projeto executando o seguinte comando:
bash
Copiar código
flutter pub get

## 3. Executando o Projeto
Dentro do projeto execute o comando "flutter_run" para inicializar o arquivo "main.dart"

# Estrutura do Código
- lib/main.dart: Ponto de entrada do aplicativo.
- lib/login_screen.dart: Tela de login com autenticação GitHub.
- lib/user_screen.dart: Tela inicial para exibição das informações do usuário autenticado.
- 

# Funções por Tela

- Tela de Login (lib/login_screen.dart)
- Faz a autenticação de login
- Tela Inicial (lib/user_screen.dart)
- Exibe as informações do usuário autenticado.

# Como funciona a autenticação com Google?
- Tela de Login: O usuário pode fazer login utilizando sua conta do Google. Após a autenticação bem-sucedida, ele é redirecionado para a tela inicial.
- Firebase Authentication: O Firebase Authentication é utilizado para gerenciar o login com o Google, facilitando a integração com o Firebase e oferecendo uma forma segura de autenticar usuários.
- Tela Inicial: Na tela inicial, o usuário verá informações sobre sua conta do Google.[

# Tela Inicial 
![image](https://github.com/user-attachments/assets/073d4ee3-b893-44a9-9525-fb18d184e846)

# Autenticação Firebase
![image](https://github.com/user-attachments/assets/7ea5faa4-7b93-4752-90c6-f332c81e1c07)



