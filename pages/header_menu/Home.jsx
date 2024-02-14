import React from 'react'
import Header from '../../components/Header'
import About from '../../components/About'
import Website_Description from '../../components/Website_Description'
import Sidebar from '../../components/sidebar'
import Searchbar from '../../components/Searchbar'
import Loader from '../../components/Loader'
import TopPlayVisits from '../../components/TopPlayVisits'
import Menu from '../../components/Menu'

const Home = () => {
    return (
        <div style={{ margin: '0px', display: 'flex', flexDirection: 'row' }}>
            <Sidebar />
            <div style={{ display: 'flex', flexDirection: 'column' }}>

                <Searchbar />
                <Loader />
                <div>
                    

                </div>
                <TopPlayVisits />
                <Header />
                <Website_Description />
                <Menu />
                <About />

            </div>


        </div>
    )
}

export default Home