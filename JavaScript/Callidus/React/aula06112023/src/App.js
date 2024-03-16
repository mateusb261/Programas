import React, { Component } from "react";
import { BrowserRouter as Router, Routes, Route } from "react-router-dom";
import Topo from "./components/Topo";
import Home from "./components/Home";
import Frontend from "./components/Frontend";
import Programacao from "./components/Programacao";
import Design from "./components/Design";
import Catalogo from "./components/Catalogo";
import Rodape from "./components/Rodape";
import NotFound from "./components/NotFound";
import Livro from "./components/Livro";

class App extends Component {
  state = {
    livros: [],
  };

  async componentDidMount() {
    try {
      const response = await fetch("./api/todosOsLivros.json");
      if (!response.ok) {
        throw new Error("Erro ao carregar os livros.");
      }
      const livros = await response.json();
      console.log(livros);
      this.setState({ livros });
      localStorage.setItem("livros", JSON.stringify(livros));
    } catch (error) {
      console.log(error);
    }
  }
  

  render() {
    return (
      <Router>
        <Topo />
        <Routes>
          <Route path="/" element={<Home livros={this.state.livros} />}
          />
          <Route path="/frontend" element={<Frontend livros={this.state.livros} />}
          />
          <Route path="/programacao" element={<Programacao livros={this.state.livros} />}
          />
          <Route path="/design" element={<Design livros={this.state.livros} />}
          />
          <Route path="/catalogo" element={<Catalogo livros={this.state.livros} />}
          />
          <Route
            path="/livro/:livroSlug"
            element={<Livro livros={JSON.parse(localStorage.getItem("livros")) || this.state.livros} />}
          />
          <Route path="/notfound" element={<NotFound />} />
        </Routes>
        <Rodape />
      </Router>
    );
  }
}

export default App;
