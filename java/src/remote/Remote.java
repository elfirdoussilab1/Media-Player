package Remote;

import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

public class Remote extends JFrame{
	
	private static final long serialVersionUID = 1L;
	
	// This Frame components of the interface
	
	private JTextArea textArea;
	private JButton createPhotoButton, createVideoButton, createFilmButton, createGroupButton, displayButton, deleteButton, playButton;
	private JTextField namePhotoField, pathPhotoField, lengthPhotoField, heightPhotoField, groupPhotoField;
	private JTextField nameVideoField, pathVideoField, durationVideoField, groupVideoField;
	private JTextField nameFilmField, pathFilmField, durationFilmField, nchaptersField, chaptersFilmField, groupFilmField;
	private JTextField nameGroupField;
	private JComboBox<String> displayGroupBox, displayMBox, deleteGroupBox, deleteMBox, playBox;
	private ButtonGroup displayButtonGroup, deleteButtonGroup;

	// We will put these elements in Panels
	JPanel mainPanel, photoPanel, videoPanel, groupPanel, filmPanel, displayPanel, deletePanel, playPanel;

	// Java Client
	private Client client;
	
	public Remote(Client client) {
		super("Java Remote Control");
		this.client = client;
	}

	/**
	 * @param strNum
	 * @return A boolean indicating wether a string is integer or not
	 */
	public boolean isNumeric(String strNum) {
		if (strNum == null) {
			return false;
		}
		try {
			int d = Integer.parseInt(strNum);
		} catch (Exception e) {
			return false;
		}
		return true;
	}

	/**
	 * @param name
	 * The constructor of our Remote Control
	 */
	public void GoClient() {
		// Creating JPanel with a GridLayout of 7 rows and 1 column
		mainPanel = new JPanel(new GridLayout(7, 1));

		// First row : Create Photo
		photoPanel = new JPanel(new FlowLayout()); 
		createPhotoButton = new JButton("Create Photo");
		createPhotoButton.setPreferredSize(new Dimension(200, 30));
		JLabel lableemail=new JLabel("Enter The name");
		namePhotoField = new JTextField("Name");
		namePhotoField.setColumns(15);
		pathPhotoField = new JTextField("Path");
		lengthPhotoField = new JTextField("Length");
		heightPhotoField = new JTextField("Height");
		groupPhotoField = new JTextField("Group");
		photoPanel.add(createPhotoButton);
		photoPanel.add(lableemail);
		photoPanel.add(namePhotoField);
		photoPanel.add(pathPhotoField);
		photoPanel.add(lengthPhotoField);
		photoPanel.add(heightPhotoField);
		photoPanel.add(groupPhotoField);

		mainPanel.add(photoPanel);

		// Creating a Video
		videoPanel = new JPanel(new FlowLayout()); 
		createVideoButton = new JButton("Create Video");
		createVideoButton.setPreferredSize(new Dimension(200, 30));
		nameVideoField = new JTextField("Enter name");
		pathVideoField = new JTextField("Enter path");
		durationVideoField = new JTextField("Enter diration");
		groupVideoField = new JTextField("Group");
		videoPanel.add(createVideoButton);
		videoPanel.add(nameVideoField);
		videoPanel.add(pathVideoField);
		videoPanel.add(durationVideoField);
		videoPanel.add(groupVideoField);

		mainPanel.add(videoPanel);

		// Creating a Group
		groupPanel = new JPanel(new FlowLayout());
		createGroupButton = new JButton("Create Group");
		createGroupButton.setPreferredSize(new Dimension(200, 30));
		nameGroupField = new JTextField("Name");
		groupPanel.add(createGroupButton);
		groupPanel.add(nameGroupField);

		mainPanel.add(groupPanel);
		
		// Display
		displayPanel = new JPanel(new FlowLayout());
		displayButton = new JButton("Display");
		displayButton.setPreferredSize(new Dimension(200, 30));
		displayPanel.add(displayButton);
		// Radio Buttons
		JPanel displayRadioPanel = new JPanel(new GridLayout(2,1));
		JRadioButton displayradio1 = new JRadioButton("Multimedia");
		displayradio1.setActionCommand("Multimedia");
        JRadioButton displayradio2 = new JRadioButton("Group");
		displayradio2.setActionCommand("Group");
		displayButtonGroup = new ButtonGroup();
		displayButtonGroup.add(displayradio1);
		displayButtonGroup.add(displayradio2);
		displayRadioPanel.add(displayradio1);
		displayRadioPanel.add(displayradio2);

		displayPanel.add(displayRadioPanel);
		displayGroupBox = new JComboBox<String>();
		displayMBox = new JComboBox<String>();
		displayPanel.add(displayMBox);
		displayPanel.add(displayGroupBox);
		// We will fill it later
		mainPanel.add(displayPanel);

		// Delete
		deletePanel = new JPanel(new FlowLayout());
		deleteButton = new JButton("Delete");
		deleteButton.setPreferredSize(new Dimension(200, 30));
		deletePanel.add(deleteButton);
		// Radio Buttons
		JPanel deleteRadioPanel = new JPanel(new GridLayout(2,1));
		JRadioButton deleteradio1 = new JRadioButton("Multimedia");
		deleteradio1.setActionCommand("Multimedia");
        JRadioButton deleteradio2 = new JRadioButton("Group");
		deleteradio2.setActionCommand("Group");
		deleteButtonGroup = new ButtonGroup();
		deleteButtonGroup.add(deleteradio1);
		deleteButtonGroup.add(deleteradio2);
		deleteRadioPanel.add(deleteradio1);
		deleteRadioPanel.add(deleteradio2);

		deletePanel.add(deleteRadioPanel);
		// Combo Box
		deleteGroupBox = new JComboBox<String>();
		deleteMBox = new JComboBox<String>();
		deletePanel.add(deleteMBox);
		deletePanel.add(deleteGroupBox);
		mainPanel.add(deletePanel);

		// Play
		playPanel = new JPanel(new FlowLayout());
		playButton = new JButton("Play");
		playButton.setPreferredSize(new Dimension(200, 30));
		playPanel.add(playButton);
		// Combo box
		playBox = new JComboBox<String>();
		playPanel.add(playBox);
		mainPanel.add(playPanel);

		// Text Area
		JScrollPane scrollPane1 = new JScrollPane(textArea = new JTextArea("Enter here", 10, 50));
		mainPanel.add(scrollPane1);

		// connecting buttons to their listeners
		createPhotoButton.addActionListener(new CreatePhotoButtonListener());
		createVideoButton.addActionListener(new CreateVideoButtonListener());
		createGroupButton.addActionListener(new CreateGroupButtonListener());
		deleteButton.addActionListener(new DeleteActionListener());
		playButton.addActionListener(new PlayActionListener());
		displayButton.addActionListener(new DisplayActionListener());

		// Setting default functions related to our Frame
		add(mainPanel);
		this.setSize(200,200);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		System.setProperty("apple.laf.useScreenMenuBar", "true");
		pack();
		setVisible(true);
		
	}
	class CreatePhotoButtonListener implements ActionListener {
		@Override
		public void actionPerformed(ActionEvent e) {
			String request = "create Photo " + namePhotoField.getText() + " " + 
			pathPhotoField.getText() + " " +lengthPhotoField.getText() + " " + heightPhotoField.getText() + " " + groupPhotoField.getText();
			// test if the length and duration are integers
			String length = lengthPhotoField.getText();
			String height = heightPhotoField.getText();
			if (isNumeric(length) && isNumeric(height)){
				String response = client.send(request);
				if(response.equals("Done")){
					textArea.setText("The Photo "+ namePhotoField.getText() + " was created successfully");
					// Add item to display
					displayMBox.addItem(namePhotoField.getText());
					deleteMBox.addItem(namePhotoField.getText());
					playBox.addItem(namePhotoField.getText());
					// Add the group name if it doesn't exist already
					String target = groupPhotoField.getText();
					boolean flag = true;
					for (int i = 0; i < displayGroupBox.getItemCount(); i++) {
						if (displayGroupBox.getItemAt(i).equals(target)) {
							flag = false;
							break;
						}
					}
					if (flag){
						displayGroupBox.addItem(groupPhotoField.getText());
						deleteGroupBox.addItem(groupPhotoField.getText());
					}
				} else{
					textArea.setText(response);
					
				}
			}else{ // non integer values
				textArea.setText("PLease enter and integer in both length and height fields");
			}
			
			repaint();
			
			
			

		}
		
	}

	class CreateVideoButtonListener implements ActionListener {
		@Override
		public void actionPerformed(ActionEvent e) {
			String request = "create Video " + nameVideoField.getText() + " " + 
			pathVideoField.getText() + " " +durationVideoField.getText() + " " + groupVideoField.getText();
			String duration = durationVideoField.getText();
			if(isNumeric(duration)){
				String response = client.send(request);
				if (response.equals("Done")){
					textArea.setText("The Video "+ nameVideoField.getText() + " was created successfully");
					// Add item to display
					displayMBox.addItem(nameVideoField.getText());
					deleteMBox.addItem(nameVideoField.getText());
					playBox.addItem(nameVideoField.getText());
					// Add the group name if it doesn't exist already
					String target = groupVideoField.getText();
					boolean flag = true;
					for (int i = 0; i < displayGroupBox.getItemCount(); i++) {
						if (displayGroupBox.getItemAt(i).equals(target)) {
							flag = false;
							break;
						}
					}
					if (flag){
						displayGroupBox.addItem(groupVideoField.getText());
						deleteGroupBox.addItem(groupVideoField.getText());
					}
					} else{
						textArea.setText(response);
						}
			}
			else{
				textArea.setText("Please enter an integer value in duration");
			}
			
			repaint();
			
			
		}
		
	}

	class CreateGroupButtonListener implements ActionListener {
		@Override
		public void actionPerformed(ActionEvent e) {
			String request = "create Group " + nameGroupField.getText() ;
			String response = client.send(request);
			if (response.equals("Done")){
				// Adding the new name to the Combo Boxes
				displayGroupBox.addItem(nameGroupField.getText());
				deleteGroupBox.addItem(nameGroupField.getText());
				textArea.setText("The Group " + nameGroupField.getText() + " was created successully !");
			}
			else{
				textArea.setText(response);
			}
			repaint();
		}
		
		
	}
	class DisplayActionListener implements ActionListener {
		@Override
		public void actionPerformed(ActionEvent e) {
			String request = "display "  + displayButtonGroup.getSelection().getActionCommand() + " ";
			 //+ displayGroupBox.getSelectedItem();
			if (displayButtonGroup.getSelection().getActionCommand().equals("Group")){
				request = request + displayGroupBox.getSelectedItem();
			}
			else{
				request = request + displayMBox.getSelectedItem();
			}
			String response = client.send(request);
			textArea.setText(response);
		}
		
	}
	
	class DeleteActionListener implements ActionListener {
		@Override
		public void actionPerformed(ActionEvent e) {
			String request = "delete "  + deleteButtonGroup.getSelection().getActionCommand() + " ";
			// + deleteBox.getSelectedItem();
			if (deleteButtonGroup.getSelection().getActionCommand().equals("Group")){
				String group_name = deleteGroupBox.getSelectedItem();
				request = request + group_name;
				String response = client.send(request);
				if(response.equals("Done")){
					deleteGroupBox.removeItem(group_name);
					displayGroupBox.removeItem(group_name);
				}
				else{
					textArea.setText(response);
				}

			}
			else{
				String m_name =  deleteMBox.getSelectedItem();
				request = request + m_name;
				String response = client.send(request);
				if (response.equals("Done")){
					deleteMBox.removeItem(m_name);
					displayMBox.removeItem(m_name);
					playBox.removeItem(m_name);
				}
				else{
					textArea.setText(response);
				}
			}
			
			repaint();
		}
		
	}
	class PlayActionListener implements ActionListener {
		@Override
		public void actionPerformed(ActionEvent e) {
			String request = "play " + playBox.getSelectedItem();
			String response = client.send(request);
			textArea.setText(response);
		}
		
	}
	
}
