package Remote;

import java.awt.*;
import java.awt.event.*;

import javax.swing.*;

public class Remote extends JFrame {
	
	private static final long serialVersionUID = 1L;
	
	// This Frame components of the interface
	
	private JTextArea textArea;
	private JButton createPhotoButton, createVideoButton, createGroupButton, displayButton, deleteButton, playButton;
	private JTextField namePhotoField, pathPhotoField, lengthPhotoField, heightPhotoField, groupPhotoField;
	private JTextField nameVideoField, pathVideoField, durationVideoField, groupVideoField;
	
	private JTextField nameGroupField;
	private JTextField deleteTextField, displayTextField, playTextField;
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

		// Text Area
		JPanel areaPanel = new JPanel();
		JLabel labelArea = new JLabel("Screen");
		JScrollPane scrollPane1 = new JScrollPane(textArea = new JTextArea("", 10, 50));
		areaPanel.add(labelArea, BorderLayout.NORTH);
		areaPanel.add(scrollPane1, BorderLayout.CENTER);
		mainPanel.add(areaPanel);

		// Second row : Create Photo
		photoPanel = new JPanel(new FlowLayout()); 
		createPhotoButton = new JButton("Create Photo");
		createPhotoButton.setPreferredSize(new Dimension(200, 50));

		JLabel labelPhotoName = new JLabel("Name:");
		namePhotoField = new JTextField("");
		namePhotoField.setColumns(10);

		JLabel labelPhotoPath = new JLabel("Path:");
		pathPhotoField = new JTextField("");
		pathPhotoField.setColumns(10);

		JLabel labelPhotoLength = new JLabel("Length:");
		lengthPhotoField = new JTextField("");
		lengthPhotoField.setColumns(10);

		JLabel labelPhotoHeight = new JLabel("Height:");
		heightPhotoField = new JTextField("");
		heightPhotoField.setColumns(10);

		JLabel labelPhotoGroup = new JLabel("Group:");
		groupPhotoField = new JTextField("");
		groupPhotoField.setColumns(10);

		photoPanel.add(createPhotoButton);

		photoPanel.add(labelPhotoName);
		photoPanel.add(namePhotoField);

		photoPanel.add(labelPhotoPath);
		photoPanel.add(pathPhotoField);

		photoPanel.add(labelPhotoLength);
		photoPanel.add(lengthPhotoField);

		photoPanel.add(labelPhotoHeight);
		photoPanel.add(heightPhotoField);

		photoPanel.add(labelPhotoGroup);
		photoPanel.add(groupPhotoField);

		mainPanel.add(photoPanel);

		// Creating a Video
		videoPanel = new JPanel(new FlowLayout()); 
		createVideoButton = new JButton("Create Video");
		createVideoButton.setPreferredSize(new Dimension(200, 50));

		JLabel labelVideoName = new JLabel("Name:");
		nameVideoField = new JTextField("");
		nameVideoField.setColumns(10);

		JLabel labelVideoPath = new JLabel("Path:");
		pathVideoField = new JTextField("");
		pathVideoField.setColumns(10);

		JLabel labelVideoDuration = new JLabel("Duration:");
		durationVideoField = new JTextField("");
		durationVideoField.setColumns(10);

		JLabel labelVideoGroup = new JLabel("Group:");
		groupVideoField = new JTextField("");
		groupVideoField.setColumns(10);

		videoPanel.add(createVideoButton);
		videoPanel.add(labelVideoName);
		videoPanel.add(nameVideoField);

		videoPanel.add(labelVideoPath);
		videoPanel.add(pathVideoField);

		videoPanel.add(labelVideoDuration);
		videoPanel.add(durationVideoField);

		videoPanel.add(labelVideoGroup);
		videoPanel.add(groupVideoField);

		mainPanel.add(videoPanel);

		// Creating a Group
		groupPanel = new JPanel(new FlowLayout());
		createGroupButton = new JButton("Create Group");
		createGroupButton.setPreferredSize(new Dimension(200, 50));

		JLabel labelGroupName = new JLabel("Name");
		nameGroupField = new JTextField("");
		nameGroupField.setColumns(10);

		groupPanel.add(createGroupButton);
		groupPanel.add(labelGroupName);
		groupPanel.add(nameGroupField);

		mainPanel.add(groupPanel);
		
		// Display
		displayPanel = new JPanel(new FlowLayout());
		displayButton = new JButton("Display");
		displayButton.setPreferredSize(new Dimension(200, 50));
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
		JLabel labelNameDisplay = new JLabel("Name:");
		displayTextField = new JTextField("");
		displayTextField.setColumns(10);

		displayPanel.add(labelNameDisplay);
		displayPanel.add(displayTextField);
		mainPanel.add(displayPanel);

		// Delete
		deletePanel = new JPanel(new FlowLayout());
		deleteButton = new JButton("Delete");
		deleteButton.setPreferredSize(new Dimension(200, 50));
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

		JLabel labelNameDelete = new JLabel("Name:");
		deleteTextField = new JTextField("");
		deleteTextField.setColumns(10);

		deletePanel.add(labelNameDelete);
		deletePanel.add(deleteTextField);
		mainPanel.add(deletePanel);

		// Play
		playPanel = new JPanel(new FlowLayout());
		playButton = new JButton("Play");
		playButton.setPreferredSize(new Dimension(200, 50));
		playPanel.add(playButton);
		JLabel labelPlay = new JLabel("Name:");
		playTextField = new JTextField("");
		playTextField.setColumns(10);
		playPanel.add(labelPlay);
		playPanel.add(playTextField);
		
		mainPanel.add(playPanel);


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
		/* 
		 *  Creates a photo when we press button
		 */
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
				} else{ textArea.setText(response);}
				
			}else{ // non integer values
				textArea.setText("PLease enter and integer in both length and height fields");
			}
			// Empty fields
			namePhotoField.setText("");
			pathPhotoField.setText("");
			lengthPhotoField.setText("");
			heightPhotoField.setText("");
			groupPhotoField.setText("");

		}
		
	}

	class CreateVideoButtonListener implements ActionListener {
		/* 
		 * Creates a Video when pressing the Button
		 */
		@Override
		public void actionPerformed(ActionEvent e) {
			String request = "create Video " + nameVideoField.getText() + " " + 
			pathVideoField.getText() + " " +durationVideoField.getText() + " " + groupVideoField.getText();
			String duration = durationVideoField.getText();
			if(isNumeric(duration)){
				String response = client.send(request);
				if (response.equals("Done")){
					textArea.setText("The Video "+ nameVideoField.getText() + " was created successfully");
				} else{
					textArea.setText(response);
				}
			}
			else{
				textArea.setText("Please enter an integer value in duration");
			}
			// Empty fields
			nameVideoField.setText("");
			pathVideoField.setText("");
			durationVideoField.setText("");
			groupVideoField.setText("");
		
		}
	}

	class CreateGroupButtonListener implements ActionListener {
		/* 
		 * Creates a Group
		 */
		@Override
		public void actionPerformed(ActionEvent e) {
			String request = "create Group " + nameGroupField.getText() ;
			String response = client.send(request);
			if (response.equals("Done")){
				textArea.setText("The Group " + nameGroupField.getText() + " was created successully !");
			}
			else{
				textArea.setText(response);
			}
			// Empty fields
			nameGroupField.setText("");
		}
		
		
	}
	class DisplayActionListener implements ActionListener {
		/* 
		 * Displays a Multimedia or a group
		 */
		@Override
		public void actionPerformed(ActionEvent e) {
			try{
				String choice = displayButtonGroup.getSelection().getActionCommand();
				String request = "display "  + choice + " " + displayTextField.getText();
				String response = client.send(request);
				textArea.setText(response);
				// Empty fields
				displayTextField.setText("");
			} catch (Exception ex){
				textArea.setText("Please make a choice and enter a name");
			}
			
		}
		
		
	}
	
	class DeleteActionListener implements ActionListener {
		/* 
		 * Deletes a Multimedia or a Group
		 */
		@Override
		public void actionPerformed(ActionEvent e) {
			try{
				String choice = deleteButtonGroup.getSelection().getActionCommand();
				String request = "delete "  +  " " + deleteTextField.getText();
				String response = client.send(request);
				if (response.equals("Done")){
					textArea.setText("Successfully deleted");
				}
				else{ textArea.setText(response);}
				// Empty fields
				deleteTextField.setText("");
			} catch(Exception ex){
				textArea.setText("Please make a choice and enter a name");
			}
			
			
			
			}
	}
		
	
	class PlayActionListener implements ActionListener {
		/* 
		 * Plays a Multimedia
		 */
		@Override
		public void actionPerformed(ActionEvent e) {
			String request = "play " + playTextField.getText();
			String response = client.send(request);
			textArea.setText(response);
			playTextField.setText("");
		}
		
	}
	
}



