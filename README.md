#Locadora


Descrição

Aplicação em C++ que visa simular as operações de uma locadora de filmes. 
Nele é possível gerenciar catálogo de filmes multi-mídia, controlar estoque, alugar filmes, cadastrar clientes, gerenciar locações, controle de aluguéis e gerenciar pagamentos.

Pré-requisitos

C++11

Instalação

Não é necessário a instalação de nenhum software externo, apenas executar o arquivo .exe.

Código-fonte

Github: https://github.com/Targ77/TP-PDS2

Licença


Não é necessária nenhuma licença externa para executar a aplicação


Documentação das funções atribuídas a esse código, separada por classes:


Produto

~Produto()

Apaga o objeto

getTitulo()

retorna titulo do filme

validaEstoque()

Verifica se o estoque é maior que 0

alugaFilme()

Retira 1 filme do estoque disponível

devolverFilme()

Adiciona 1 filme ao estoque disponível

aumentarEstoque(int qtd)

Aumenta o estoque no tamanho declarado em qtd

diminuirEstoque(int qtd)

Diminuí o estoque no tamanho declarado em qtd, caso seja possível


Fita

Fita(int codigo, int quantidade, const std::string&titulo)

Recebe 1 inteiro positivo que representa o codigo, 1 inteiro positivo que representa a quantidade e 1 string que representa o título
Cria uma Fita com esses dados

calcularPreco(int diasLocacao)

Calcula o preço baseado na multiplicação do preço base vezes os dias que a fita foi alugada(diasLocacao), mais um taxa caso a fita não seja rebobinada

imprimir()

Imprime os dados da fita

getCodigo()

Retorna o código da fita


DVD

DVD(int codigo, int quantidade, const std::string&titulo, const std::string& categoria)

Recebe 1 inteiro positivo que representa o codigo, 1 inteiro positivo que representa a quantidade, 1 string que representa o título e 1 string que representa a categoria do DVD
Cria um DVD com esses dados

calcularPreco(int diasLocacao)

Calcula o preço baseado na multiplicação do preço base vezes os dias que a fita foi alugada(diasLocacao).



imprimir()

Imprime os dados da fita

getCodigo()

Retorna o código da fita

getCategoria(const std::string& categoria)

Retorna a categoria do filme.



Cliente

Cliente(const std::string&cpf, const std::string& nome)

Recebe 1 string que possui apenas numeros inteiros positivos que representa o CPF e 1 string que representa o nome
Cria um cliente com esses dados

imprimirInformacoes()

Imprime os dados do cliente

getCPF()

Retorna o CPF

getNome()

Retorna o nome

getFilmes()

Retorna um vetor de inteiros com os códigos dos filmes alugados

addFilme(int filme)

Adiciona o código de um filme(filme) alugado

devolverFilmes()

Devolve todos os filmes alugados à locadora

Estoque

adicionarFita(int codigo, int quantidade, const std::string&titulo)

Chama o construtor de Fita com esses dados e adiciona o objeto em um mapa de produtos

adicionarDVD(int codigo, int quantidade, const std::string&titulo, const std::string& categoria)

Chama o construtor de DVD com esses dados e adiciona o objeto em um mapa de produtos

removerProduto(int codigo)

Remove o produto com o código(codigo) presente no mapa

buscarProduto(int codigo)

Retorna um ponteiro do produto com o código(codigo) presente no mapa

imprimirRelatorio()

Imprime os dados do estoque

lerArquivoCadastro(const std::string& nomeArquivo)

Lê os dados armazenados em um arquivo(nomeArquivo) e cadastra todos os filmes descritos nele

validaProdutoLocacao(int codigo)

Verifica se o filme com o código declarado(codigo) realmente existe

validaProdutoEstoque(int codigo)

Verifica se o filme com o código declarado(codigo) está disponível no estoque

devolveLocacao(int codigo, int dias)

Devolve o filme alugado(codigo) ao estoque e calcula o valor a ser pago baseado nos dias alugado(dias)

alugaProduto(int codigo)

Aluga 1 filme do código declarado(codigo)

imprimirRelatorioOrdenadoPorTitulo()

Imprime o título de todos os filmes no estoque

aumentarEstoque(int codigo, int qtd)

aumenta o estoque do filme(codigo) no valor delarado(qtd)

diminuirEstoque(int codigo, int qtd)

diminui o estoque do filme(codigo) no valor declarado(qtd), caso seja possível


ControleCliente

adicionarCliente(const std::string& cpf, const std::string& nome)

Cria um cliente com os dados fornecidos e o adiciona no mapa de clientes

removerCliente(const std::string&cpf)

Deleta o cliente cujo cpf foi decalrado(cpf)

imprimirRelatorio()

Imprime as informações dos clientes cadastrados

encontrarCliente(const std::string& cpf)

Retorna um ponteiro do cliente requerido(cpf)

alugarFilme(const std::string& cpf, int codigo)

Aluga o filme requerido(codigo) para o cliente determinado(cpf)

devolverFilmes(cosnt std::string& cpf)

Devolve todos os filmes do cliente determinado(cpf)

validaCliente(cosnt std::string&cpf)

Verifica se o cliente(cpf) está cadastrado

estaAlugado(int codigo)

Verifica se o filme declarado(codigo) está alugado
imprimirRelatorioOrdenadoPorNome()

Imprime a lista de clientes cadastrado

Locadora

lerArquivoCadastro(cont std::string& nomearquivo)

Realiza o cadastro dos dados declarados no arquivo(nomeArquivo)

cadastrarFita(int codigo, int quantidade, const std::string& titulo)

Recebe 1 inteiro positivo que representa o codigo, 1 inteiro positivo que representa a quantidade e 1 string que representa o título
Cria uma Fita com esses dados
Adiciona essa fita ao estoque

cadastrarDVD(int codigo, int quantidade, const std::string& titulo, const std::string& categoria)


Recebe 1 inteiro positivo que representa o codigo, 1 inteiro positivo que representa a quantidade, 1 string que representa o título e 1 string que representa a categoria do DVD
Cria um DVD com esses dados
Adiciona esse DVD ao estoque

removerProduto(int codigo)

Remove o filme declarado(codigo) do estoque

listarProdutosOrdenadosPorCodigo()

Lista os produtos presentes no estoque por código

listaProdutosOrdenadosPorTitulo()

Lista os produtos presentes no estoque por título

cadastrarCliente(const std::string& cpf, const std::string& nome)

Cadastra um cliente no banco de dados a partir dos dados recebidos

removerCliente(const std::string& cpf)

Remove o cliente requerido(cpf) do banco de dados
listarProdutosOrdenadosPorCPF()

Lista os clientes presentes no banco de dados por CPF

listarProdutosOrdenadosPorNome()

Lista os clientes presentes no banco de dados por Nome

alugarFilme(const std::string& cpf, std::vector<int> filmesAlugados)

Aluga os filmes requeridos(filmesAlugados) para o cliente requerente(cpf)

devolverFilme(const std::string& cpf, int diasLocacao)

Devolve os filmes alugados pelo cliente(cpf) e calcula o valor relativo(diasLocacao)

aumentarEstoque(int codigo, int qtd)

Aumenta o estoque do produto requerido(codigo) na quantidade desejada(qtd)

diminuirEstoque(int codigo, int qtd)

Diminui o estoque do produto requerido(codigo) na quantidade desejada(qtd), caso seja possível
