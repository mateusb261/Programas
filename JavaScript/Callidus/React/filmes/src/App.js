import React, { Component } from "react";
import TabelaHead from "./components/TabelaHead";
import TabelaFoot from "./components/TabelaFoot";
import TabelaBody from "./components/TabelaBody";
import "./index.css";
import BarraPesquisa from "./components/BarraPesquisa";

class App extends Component {
  state = {
    filmes: [],
  };

  componentDidMount() {
    fetch("/api/filmes.json")
      .then((response) => response.json())
      .then((filmes) => this.setState({ filmes }))
      .catch(function (error) {
        console.log("Erro na requisição");
      })
      .finally(function () {
        console.log("Sempre retorna");
      });
  }

  handleRemoveLinha = (titulo) => {
    const filmes = this.state.filmes.filter((l) => l.titulo !== titulo);
    this.setState({ filmes });
  };

  handleOrdenarCrescente = (titulo) => {
    const filmes = this.state.filmes.sort((a, b) =>
      a.titulo < b.titulo ? -1 : 0
    );
    this.setState({ filmes });
  };

  handleOrdenarDecrescente = (titulo) => {
    const filmes = this.state.filmes.sort((a, b) =>
      a.titulo > b.titulo ? -1 : 0
    );
    this.setState({ filmes });
  };

  handlePesquisa = (titulo) => {
    fetch("/api/filmes.json")
    .then((response) => response.json())
    .then((filmes) => {
      filmes = filmes.filter((l) => l.titulo.startsWith(titulo));
      this.setState({filmes})
    }
)
  };

  render() {
    return (
      <div>
        <BarraPesquisa 
          pesquisa = {this.handlePesquisa}
        />
        <table className="tabela">
          <TabelaHead 
            ordenarCrescente = {this.handleOrdenarCrescente}
            ordenarDecrescente = {this.handleOrdenarDecrescente}
          />
          <TabelaBody
            filmes={this.state.filmes}
            removerLinha={this.handleRemoveLinha}
          />
          <TabelaFoot qdeFilmes={this.state.filmes.length} />
        </table>
      </div>

    );
  }
}

export default App;
