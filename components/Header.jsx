import React from 'react';
import Container from 'react-bootstrap/Container';
import Nav from 'react-bootstrap/Nav';
import Navbar from 'react-bootstrap/Navbar';
import NavDropdown from 'react-bootstrap/NavDropdown';

const Header = () => {
    return (
        <div style={{ marginLeft: '20px', marginTop: '2px', marginRight: '20px' }}>

            <Navbar expand="lg" className="bg-body-tertiary">
                <Container>
                    <Navbar.Brand href="/home">Nouva-Neons</Navbar.Brand>
                    <Navbar.Toggle aria-controls="basic-navbar-nav" />
                    <Navbar.Collapse id="basic-navbar-nav">
                        <Nav className="ms-auto">
                            <Nav.Link href="/home">Home</Nav.Link>
                            <Nav.Link href="/skills_summary">Skills Summary</Nav.Link>
                            <Nav.Link href="/certificates">Certificates</Nav.Link>
                            <Nav.Link href="/projects">Projects</Nav.Link>
                            <Nav.Link href="/files">Files</Nav.Link>
                            <Nav.Link href="/game_modules">Game Modules</Nav.Link>
                            <Nav.Link href="/mobile_apps">Mobile Apps</Nav.Link>
                            <Nav.Link href="/computer_applications">Computer Applications</Nav.Link>
                            <Nav.Link href="/external_people">External People</Nav.Link>
                            <Nav.Link href="/about_2">About</Nav.Link>
                            <Nav.Link href="/contacts">Contacts</Nav.Link>
                            <Nav.Link href="/links">Links</Nav.Link>
                            <Nav.Link href="/accounts">Accounts</Nav.Link>
                            <NavDropdown title="Extras" id="basic-nav-dropdown">
                                <NavDropdown.Item href="#action/3.1">Social Socials</NavDropdown.Item>
                                <NavDropdown.Item href="#action/3.2">Technical Socials</NavDropdown.Item>
                                <NavDropdown.Item href="#action/3.2">Musical Socials</NavDropdown.Item>
                                <NavDropdown.Item href="#action/3.2">Artistic Socials</NavDropdown.Item>
                                <NavDropdown.Item href="#action/3.2">All Socials</NavDropdown.Item>
                                <NavDropdown.Item href="#action/3.3">History</NavDropdown.Item>

                                <NavDropdown.Divider />
                                <NavDropdown.Item href="#action/3.4">
                                    Separated link
                                </NavDropdown.Item>
                            </NavDropdown>
                        </Nav>
                    </Navbar.Collapse>
                </Container>
            </Navbar>

        </div>

    );
}

export default Header