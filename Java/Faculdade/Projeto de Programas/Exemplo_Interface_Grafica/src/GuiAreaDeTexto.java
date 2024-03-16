import java.awt.event.*;

import javax.swing.*;

public class GuiAreaDeTexto extends JPanel {
    private JTextField tfCampo;
    private JTextArea taTexto;
    private JScrollPane scrollPane;
    private JButton btLimpar;
	private JLabel lbNome;
	private JLabel lbMsg;
    private final static String novaLinha = "\n";

    public GuiAreaDeTexto() {
        inicializarComponentes();
        definirEventos();
    }

    private void inicializarComponentes() {
        setLayout(null);
        tfCampo = new JTextField();
        taTexto = new JTextArea(5, 20); 
        taTexto.setEditable(true);
        btLimpar = new JButton(new ImageIcon("imagens/borracha.jpg"));
        scrollPane = new JScrollPane(taTexto);
        
        lbNome = new JLabel("Nome:");
        lbMsg = new JLabel("Mensagem:");
        tfCampo.setBounds(85, 15, 150, 25);
        scrollPane.setBounds(85, 45, 300, 120);
        btLimpar.setBounds(85,170,50,50);
        lbNome.setBounds(5, 15, 80, 25);
        lbMsg.setBounds(5, 45, 80, 25);
        add(tfCampo);
        add(scrollPane);
        add(btLimpar);
        add(lbNome);
        add(lbMsg);
    }

    private void definirEventos() {
        tfCampo.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                tfCampo.selectAll();
                taTexto.append(tfCampo.getText() + novaLinha);
                taTexto.setCaretPosition(taTexto.getDocument().getLength());
            }
        });
        btLimpar.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                tfCampo.setText("");
                taTexto.setText("");
            }
        });
    }
}