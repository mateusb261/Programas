import React from 'react';
import { Link } from 'react-router-dom';

const NotFound = () => (
  <div style={{ textAlign: 'center', padding: '20px' }}>
    <h2 style={{ fontSize: '24px', margin: '10px' }}>404 - Página não encontrada</h2>
    <p style={{ fontSize: '16px' }}>A página que você está procurando não foi encontrada ou foi removida.</p>
      <Link to="/" style={{ color: '#0074d9', textDecoration: 'none', fontWeight: 'bold', marginLeft: '10px' }}>
        Ir para a página inicial</Link>
  </div>
);

export default NotFound;
