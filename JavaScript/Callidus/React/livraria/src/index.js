import React from 'react';
import ReactDOM from 'react-dom/client';
import './index.css';
import App from './App';
import * as serviceWorker from './serviceWorker';

const tudo = ReactDOM.createRoot(document.getElementById("tudo"));
tudo.render(<App />);

serviceWorker.unregister();
