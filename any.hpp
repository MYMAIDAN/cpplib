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
            m_AnyImp = new any_storage<U>(val);
        }
        private:
        class any_base 
        {
        };

        template<class T>
        class any_storage : public any_base
        {
            
            public:
            any_storage(T val) : m_Data(val) 
            {}
            T m_Data;
        };

        any_base*  m_AnyImp{nullptr};

        template<class F>
        friend F any_cast(any& obj);
    };

    template<class F>
    F any_cast(any& obj)
    {
        auto any_obj = static_cast<any::any_storage<F>*>(obj.m_AnyImp);
        if(any_obj != nullptr)
        {
            return any_obj->m_Data;
        }
    }


}