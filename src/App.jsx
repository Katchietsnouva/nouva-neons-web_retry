import { useState } from 'react'
{
  /* The following line can be included in your src/index.js or App.js file */
}
import { BrowserRouter, Routes, Route, Link } from 'react-router-dom';
import 'bootstrap/dist/css/bootstrap.min.css';
import Certificates from '../pages/header_menu/Certificates';
import Projects from '../pages/header_menu/Projects';
import NoPage from '../pages/header_menu/NoPage';
import Home from '../pages/header_menu/Home';
import Skills_summary from '../pages/header_menu/Skills_summary';
import Files from '../pages/header_menu/Files';
import Game_modules from '../pages/header_menu/Game_modules';
import Mobile_apps from '../pages/header_menu/Mobile_apps';
import Computer_applications from '../pages/header_menu/Computer_applications';
import External_people from '../pages/header_menu/External_people';
import About_2 from '../pages/header_menu/About_2';
import Contacts from '../pages/header_menu/Contacts';
import Links from '../pages/header_menu/Links';
import Accounts from '../pages/header_menu/Accounts';
import { NavLink } from 'react-bootstrap';

function App() {
  const [count, setCount] = useState(0)

  return (
    <div>
      <BrowserRouter>
        {/* <header>
          <nav>
            <NavLink to="/Home">Home</NavLink>
            <NavLink to="/Certificates">Files</NavLink>
          </nav>
        </header> */}
        <main>
          <Routes>
            <Route index element={<Home />} />
            <Route path='/Home' element={<Home />} />
            <Route path='/Certificates' element={<Certificates />} />
            <Route path='/Projects' element={<Projects />} />
            <Route path='/Skills_summary' element={<Skills_summary />} />
            <Route path='/Files' element={<Files />} />
            <Route path='/Game_modules' element={<Game_modules />} />
            <Route path='/mobile_apps' element={<Mobile_apps />} />
            <Route path='/computer_applications' element={<Computer_applications />} />
            <Route path='/External_people' element={<External_people />} />
            <Route path='/about_2' element={<About_2 />} />
            <Route path='/contacts' element={<Contacts />} />
            <Route path='/links' element={<Links />} />
            <Route path='/accounts' element={<Accounts />} />
            <Route path='*' element={<NoPage />} />
          </Routes>
        </main>
      </BrowserRouter>
    </div>
  )
}

export default App