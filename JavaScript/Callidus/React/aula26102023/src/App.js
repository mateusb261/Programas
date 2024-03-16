import React, { Component } from "react";
import Topo from "./components/Topo";
import Rodape from "./components/Rodape";
import { Route, BrowserRouter as Router, Routes } from "react-router-dom";
import Home from "./components/Home";
import Frontend from "./components/Frontend";
import Programacao from "./components/Programacao";
import Catalogo from "./components/Catalogo";
import NotFound from "./components/NotFound";
import Design from "./components/Design";
import "./index.css"
import Livro from "./components/Livro";
import axios from "axios";

class App extends Component{
  state ={
    livros: []
  };

  async componentDidMount(){
    try{
      const{data : livros} = await axios.get("/api/todoOsLivros.json");
      this.setState({livros});
    }catch(error){
      console.log(error);
      document
        .querySelectorAll(".principal")[0]
        .insertAdjacentHTML(
          "beforeend",
          "<p class='erro'>Mensagem de erro</p>"
        );
    }
    
  }

  render(){
    return(
      <Router>
        <Topo/>
          <Routes>
            <Route exact path="/"
              render={() => <Home livros= {this.state.livros}/>}/>
            <Route exact path="frontend" 
              render={()=> <Frontend livros={this.state.livros}/>}/>
            <Route exact path="programacao" 
              render={()=> <Programacao livros={this.state.livros}/>}/>
            <Route exact path="design" 
              render={()=> <Design livros={this.state.livros}/>}/>
            <Route exact path="catalogo" 
              render={(props)=> <Catalogo livros={this.state.livros}/>}/>
            <Route path="/livro/:livroSlug" 
              render={props => {
                const livro = this.state.livros.find(
                  livro => livro.slug === props.match.params.livroSlug
                );
                if(livro) return <Livro livro={livro} />
                else return <NotFound />
              }}/>
            <Route component={NotFound}/>
          </Routes>
          <Rodape />
      </Router>
    );
  }
}
export default App;