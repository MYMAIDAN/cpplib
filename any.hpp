namespace mtl
{
    /**
     * @brief class any is object which can hold any data type
     * 
     */
    class any
    {
        public:
        template<class U>
        any(U val) 
        {
            m_AnyImp = new any_storage<U>();
        }
        private:
        class any_base 
        {
        };

        template<class T>
        class any_storage : public any_base
        {
            T* data{nullptr};
            public:
            any_storage(T)
        };

        any_base*  m_AnyImp{nullptr};
        

    };
}