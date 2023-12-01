<h1>Locadora</h1>

<h1>Descrição</h1>

Aplicação em C++ que visa simular as operações de uma locadora de filmes. 
Nele é possível gerenciar catálogo de filmes multi-mídia, controlar estoque, alugar filmes, cadastrar clientes, gerenciar locações, controle de aluguéis e gerenciar pagamentos.

<h1>Pré-requisitos</h1>

C++11

<h1>Instalação</h1>


Não é necessário a instalação de nenhum software externo, apenas executar o arquivo .exe.

<h1>Código-fonte</h1>

Github: https://github.com/Targ77/TP-PDS2

<h1>Licença</h1>

Não é necessária nenhuma licença externa para executar a aplicação

<h1>Documentação das funções atribuídas a esse código, separada por classes</h1>

<h1>Produto</h1>

~Produto()

- Apaga o objeto

getTitulo()

- Retorna titulo do filme

validaEstoque()

- Verifica se o estoque é maior que 0

alugaFilme()

- Retira 1 filme do estoque disponível

devolverFilme()

- Adiciona 1 filme ao estoque disponível

aumentarEstoque(int qtd)

- Aumenta o estoque no tamanho declarado em qtd

diminuirEstoque(int qtd)

- Diminuí o estoque no tamanho declarado em qtd, caso seja possível

<h1>Fita</h1>

Fita(int codigo, int quantidade, const std::string&titulo)

- Recebe 1 inteiro positivo que representa o codigo, 1 inteiro positivo que representa a quantidade e 1 string que representa o título
- Cria uma Fita com esses dados

calcularPreco(int diasLocacao)

- Calcula o preço baseado na multiplicação do preço base vezes os dias que a fita foi alugada(diasLocacao), mais um taxa caso a fita não seja rebobinada

imprimir()

- Imprime os dados da fita

getCodigo()

- Retorna o código da fita

<h1>DVD</h1>

DVD(int codigo, int quantidade, const std::string&titulo, const std::string& categoria)

- Recebe 1 inteiro positivo que representa o codigo, 1 inteiro positivo que representa a quantidade, 1 string que representa o título e 1 string que representa a categoria do DVD
- Cria um DVD com esses dados

calcularPreco(int diasLocacao)

- Calcula o preço baseado na multiplicação do preço base vezes os dias que a fita foi alugada(diasLocacao).

imprimir()

- Imprime os dados da fita

getCodigo()

- Retorna o código da fita

getCategoria(const std::string& categoria)

- Retorna a categoria do filme.

<h1>Cliente</h1>

Cliente(const std::string&cpf, const std::string& nome)

- Recebe 1 string que possui apenas numeros inteiros positivos que representa o CPF e 1 string que representa o nome
- Cria um cliente com esses dados

imprimirInformacoes()

- Imprime os dados do cliente

getCPF()

- Retorna o CPF

getNome()

- Retorna o nome

getFilmes()

- Retorna um vetor de inteiros com os códigos dos filmes alugados

addFilme(int filme)

- Adiciona o código de um filme(filme) alugado

devolverFilmes()

- Devolve todos os filmes alugados à locadora

<h1>Estoque</h1>

adicionarFita(int codigo, int quantidade, const std::string&titulo)

- Recebe 1 inteiro positivo que representa o codigo, 1 inteiro positivo que representa a quantidade e 1 string que representa o título
- Cria uma Fita com esses dados
- Adiciona essa fita ao estoque

adicionarDVD(int codigo, int quantidade, const std::string&titulo, const std::string& categoria)

- Recebe 1 inteiro positivo que representa o codigo, 1 inteiro positivo que representa a quantidade, 1 string que representa o título e 1 string que representa a categoria
- Cria um DVD com esses dados
- Adiciona essa fita ao estoque

removerProduto(int codigo)

- Remove o produto com o código(codigo) presente no mapa

buscarProduto(int codigo)

- Retorna um ponteiro do produto com o código(codigo) presente no mapa

imprimirRelatorio()

- Imprime os dados do estoque

lerArquivoCadastro(const std::string& nomeArquivo)

- Lê os dados armazenados em um arquivo(nomeArquivo) e cadastra todos os filmes descritos nele

validaProdutoLocacao(int codigo)

- Verifica se o filme com o código declarado(codigo) realmente existe

validaProdutoEstoque(int codigo)

- Verifica se o filme com o código declarado(codigo) está disponível no estoque

devolveLocacao(int codigo, int dias)

- Devolve o filme alugado(codigo) ao estoque e calcula o valor a ser pago baseado nos dias alugado(dias)

alugaProduto(int codigo)

- Aluga 1 filme do código declarado(codigo)

imprimirRelatorioOrdenadoPorTitulo()

- Imprime o título de todos os filmes no estoque

aumentarEstoque(int codigo, int qtd)

- aumenta o estoque do filme(codigo) no valor delarado(qtd)

diminuirEstoque(int codigo, int qtd)

- diminui o estoque do filme(codigo) no valor declarado(qtd), caso seja possível

<h1>ControleCliente</h1>

adicionarCliente(const std::string& cpf, const std::string& nome)

- Cria um cliente com os dados fornecidos e o adiciona no mapa de clientes

removerCliente(const std::string&cpf)

- Deleta o cliente cujo cpf foi decalrado(cpf)

imprimirRelatorio()

- Imprime as informações dos clientes cadastrados

encontrarCliente(const std::string& cpf)

- Retorna um ponteiro do cliente requerido(cpf)

alugarFilme(const std::string& cpf, int codigo)

- Aluga o filme requerido(codigo) para o cliente determinado(cpf)

devolverFilmes(cosnt std::string& cpf)

- Devolve todos os filmes do cliente determinado(cpf)

validaCliente(cosnt std::string&cpf)

- Verifica se o cliente(cpf) está cadastrado

estaAlugado(int codigo)

- Verifica se o filme declarado(codigo) está alugado

imprimirRelatorioOrdenadoPorNome()

- Imprime a lista de clientes cadastrado

<h1>Locadora</h1>

lerArquivoCadastro(cont std::string& nomearquivo)

- Realiza o cadastro dos dados declarados no arquivo(nomeArquivo)

cadastrarFita(int codigo, int quantidade, const std::string& titulo)

- Recebe 1 inteiro positivo que representa o codigo, 1 inteiro positivo que representa a quantidade e 1 string que representa o título
- Cria uma Fita com esses dados
- Adiciona essa fita ao estoque

cadastrarDVD(int codigo, int quantidade, const std::string& titulo, const std::string& categoria)


- Recebe 1 inteiro positivo que representa o codigo, 1 inteiro positivo que representa a quantidade, 1 string que representa o título e 1 string que representa a categoria do DVD
- Cria um DVD com esses dados
- Adiciona esse DVD ao estoque

removerProduto(int codigo)

- Remove o filme declarado(codigo) do estoque

listarProdutosOrdenadosPorCodigo()

- Lista os produtos presentes no estoque por código

listaProdutosOrdenadosPorTitulo()

- Lista os produtos presentes no estoque por título

cadastrarCliente(const std::string& cpf, const std::string& nome)

- Cadastra um cliente no banco de dados a partir dos dados recebidos

removerCliente(const std::string& cpf)

- Remove o cliente requerido(cpf) do banco de dados

listarProdutosOrdenadosPorCPF()

- Lista os clientes presentes no banco de dados por CPF

listarProdutosOrdenadosPorNome()

- Lista os clientes presentes no banco de dados por Nome

alugarFilme(const std::string& cpf, std::vector<int> filmesAlugados)

- Aluga os filmes requeridos(filmesAlugados) para o cliente requerente(cpf)

devolverFilme(const std::string& cpf, int diasLocacao)

- Devolve os filmes alugados pelo cliente(cpf) e calcula o valor relativo(diasLocacao)

aumentarEstoque(int codigo, int qtd)

- Aumenta o estoque do produto requerido(codigo) na quantidade desejada(qtd)

diminuirEstoque(int codigo, int qtd)

- Diminui o estoque do produto requerido(codigo) na quantidade desejada(qtd), caso seja possível
