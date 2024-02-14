import React, { useEffect, useState } from 'react';
import Button from 'react-bootstrap/Button';
import Card from 'react-bootstrap/Card';

const Menu = () => {
    const [imageFilenames, setImageFilenames] = useState([]);

    useEffect(() => {
        // Dynamically import image filenames with multiple formats from the 'images' directory
        importImages();
    }, []);

    const importImages = async () => {
        try {
            const imageContext = await import.meta.glob('../assets/images/*.{jpg,jpeg,webp,png,gif,avif}'); // Adjust the formats and path as needed
            const filenames = Object.keys(imageContext);

            setImageFilenames(filenames);
        } catch (error) {
            console.error('Error importing images:', error);
        }
    };

    const getImageNameWithoutExtension = (filename) => {
        // Remove the file extension from the filename
        const parts = filename.split('/').pop().split('.');
        const nameWithoutExtension = parts.slice(0, parts.length - 1).join('.');
        return nameWithoutExtension;
    };

    return (
        <div>
            <h1 style={{marginLeft:'40px'}}>Menu:</h1>
            <div style={{ margin: '20px', display: 'flex', flexWrap: 'wrap', justifyContent: 'space-between' }}>
                {imageFilenames.map((filename, index) => (
                    <Card key={index} style={{ width: '16rem' }}>
                        <Card.Img variant="top" src={filename} alt={`Image ${index}`} style={{ height: '9rem' }} />
                        <Card.Body>
                            <Card.Title>{getImageNameWithoutExtension(filename)}</Card.Title> {/* Display image name without extension as Card Title */}
                            <Card.Text>
                                Check out the content below.
                            </Card.Text>
                            <Button variant="primary">Dive into more</Button>
                        </Card.Body>
                    </Card>
                ))}
            </div>


        </div>

    );
};

export default Menu;
