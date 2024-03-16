import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class GuiLogin extends JFrame {

	private JTextField tfLogin;
	private JLabel lbSenha;
	private JLabel lbLogin;
	private JButton btLogar;
	private JButton btCancelar;
	private JPasswordField pfSenha;
	private static GuiLogin frame;
	
	public GuiLogin(){
		inicializarComponentes();
		definirEventos();
	}
	
	public void inicializarComponentes(){
		setTitle("Login no Sistema");
		setBounds(0,0, 250,200);
		setLayout(null);
		tfLogin = new JTextField(5);
		pfSenha = new JPasswordField(5);
		lbSenha = new JLabel("Senha:");
		lbLogin = new JLabel("Login:");
		btLogar = new JButton("Logar");
		btCancelar = new JButton("Cancelar");
		tfLogin.setBounds(100, 30, 120, 25);
		lbLogin.setBounds(30, 30, 80, 25);
		lbSenha.setBounds(30, 75, 80, 25);
		pfSenha.setBounds(100, 75, 120, 25);
		btLogar.setBounds(20, 120, 100, 25);
		btCancelar.setBounds(125, 120, 100, 25);
		add(tfLogin);
		add(lbSenha);
		add(lbLogin);
		add(btLogar);
		add(btCancelar);
		add(pfSenha);
	}
	
	private void definirEventos(){
		
		btLogar.addActionListener(new ActionListener () {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				
				String senha = String.valueOf(pfSenha.getPassword());
				if(tfLogin.getText().equals("fabio") && senha.equals("123")){
					frame.setVisible(false);
					GuiMenuPrincipal.abrir();
				}
				else {
					JOptionPane.showMessageDialog(null, "Login ou senha incorreta");
				}
				
			}
		});
	
		btCancelar.addActionListener(new ActionListener() {
				
				@Override
				public void actionPerformed(ActionEvent e) {
					System.exit(0);
					
				}
		});
	
	}	
	
	public static void main(String[] args) {	
		
		frame = new GuiLogin();
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setLocation(500,100);
		frame.setVisible(true);			
		
	}
}



