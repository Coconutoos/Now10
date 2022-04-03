# Now10
Integrantes:
<ul>
  <li>Amin Mhamad Ismail
  <li>Gustavo Teixeira Ayala
</ul>
<hr>
<h3>Diagrama de Caso de Uso</h3>
<img src="/DiagCasoDeUso.png" alt="Diagrama de caso de uso">
<h3>Diagrama de Atividades (Caso de uso: Gerar Relatório)</h3>
<img src="/DiagramaDeAtividades.png" alt="Fluxograma do caso de uso">
<hr>
<h3>Descrição do Caso de Uso</h3>
<table>
  <tr>
    <td>Titulo do caso de uso</td>
    <td>Manter dados de clientes</td>
  </tr>
  <tr>
    <td>Objetivo</td>
    <td>O usuário tem a possibilidade de remover, alterar ou consultar os dados cadastrados de um cliente</td>
  </tr>
  <tr>
    <td>Ator(es)</td>
    <td>Usuário do sistema</td>
  </tr>
  <tr>
    <td>Pré-Condições</td>
    <td>Ter o cliente cadastrado no sistema</td>
  </tr>
  <tr>
    <td>Fluxo 1</td>
    <td>1.	O usuário cadastra os dados de um cliente no sistema.<br>2.	A lista de ID`s cadastrados é mostrados na tela.<br>3.	O usuário consulta os dados do cliente.<br>4.	A lista de ID`s cadastrados é mostrada na tela.<br>5.	O caso de uso se encerra.</td>
  </tr>
  <tr>
    <td>Fluxo 2</td>
    <td>1.	O usuário cadastra os dados de um cliente no sistema.<br>2.	A lista de ID`s cadastrados é mostrados na tela.<br>3.	O usuário remove os dados do cliente.<br>4.	A lista de ID`s cadastrados é mostrada na tela.<br>5.	O caso de uso se encerra.</td>
  </tr>
</table><hr>
<h3>Funcionamento do Software</h3>
<p>A tela inicial do software conta com as seguintes opções:<p>
<ol>
  <li><a href="#cadastrarCliente">Cadastrar Cliente</a>
  <li><a href="#removerCliente">Remover Cliente
  <li><a href="#alterarCliente">Alterar Cliente
  <li><a href="#consultarCliente">Consultar Cliente
  <li><a href="#cadastrarAlimento">Cadastrar Alimento
  <li><a href="#removerAlimento">Remover Alimento
  <li><a href="#alterarAlimento">Alterar Alimento
  <li><a href="#consultarAlimento">Consultar Alimento
  <li><a href="#gerarRelatorio">Gerar Relatório
  <li><a href="#sair">Sair
</ol>
<br>
<h4><a name="cadastrarCliente">Cadastrar Cliente</h4></a>
<p>O usuário fornece os dados necessários para realizar o cadastro do cliente no sistema.</p>
    <em><p>Pré-Condições: Nenhuma</p>
      <p>Pós-Condições: O cliente é cadastrado no sistema.</p></em>
<h4><a name="removerCliente">Remover Cliente</h4></a>
<p>Após o usuário fornecer o ID, o cliente cadasrado no ID é removido do sistema.</p>
    <em><p>Pré-Condições: ID de um cliente existente.</p>
      <p>Pós-Condições: O cliente é removido do sistema.</p></em>
<h4><a name="alterarCliente">Alterar Cliente</h4></a>
<p>Após fornecer o ID, o usuário tem a possibilidade de alterar os dados cadastrados do cliente.</p>
    <em><p>Pré-Condições: ID de um cliente existente.</p>
      <p>Pós-Condições: Os dados do cliente são alterados.</p></em>
<h4><a name="consultarCliente">Consultar Cliente</h4></a>
<p>O usuário fornece o ID de um cliente e o programa mostra as informações cadastradas sobre aquele ID.</p>
    <em><p>Pré-Condições: ID de um cliente existente.</p>
      <p>Pós-Condições: As informações sobre o cliente são impressas na tela.</p></em>
<h4><a name="cadastrarAlimento">Cadastrar Alimento</h4></a>
<p>O usuário fornece os dados necessários para realizar o cadastro do alimento no sistema.</p>
    <em><p>Pré-Condições: Nenhuma</p>
      <p>Pós-Condições: O alimento é cadastrado no sistema.</p></em>
<h4><a name="removerAlimento">Remover Alimento</h4></a>
<p>Após o usuário fornecer o ID, o alimento cadasrado no ID é removido do sistema.</p>
    <em><p>Pré-Condições: ID de um alimento existente.</p>
      <p>Pós-Condições: O alimento é marcado como removido.</p></em>
<h4><a name="alterarAlimento">Alterar Alimento</h4></a>
<p>Após fornecer o ID, o usuário tem a possibilidade de alterar os dados cadastrados do alimento.</p>
    <em><p>Pré-Condições: ID de um alimento existente.</p>
      <p>Pós-Condições: Os dados do alimento são alterados.</p></em>
<h4><a name="consultarAlimento">Consultar Alimento</h4></a>
<p>O usuário fornece o ID de um alimento e o programa mostra as informações cadastradas sobre aquele ID.</p>
    <em><p>Pré-Condições: ID de um alimento existente.</p>
      <p>Pós-Condições: As informações sobre o alimento são impressas na tela.</p></em>
<h4><a name="gerarRelatorio">Gerar Relatório</h4></a>
<p>O programa gera um relatório e salva no local onde ele está localizado.</p>
    <em><p>Pré-Condições: Nenhuma.</p>
    <p>Pós-Condições: As informações sobre os cliente e os alimentos são salvos em um novo arquivo.</p></em>
<h4><a name="sair">Sair</h4></a>
<p>A aplicação é encerrada. (Opção 0 no programa)</p>
    <em><p>Pré-Condições: Nenhuma.</p>
      <p>Pós-Condições: O programa encerra.</p></em>
