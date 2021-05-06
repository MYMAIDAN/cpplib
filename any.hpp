#include <type_traits>
#include <typeinfo>

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
            public:
            virtual const std::type_info& getType() = 0;
        };

        template<class T>
        class any_storage : public any_base
        {
            
            public:
            any_storage(T val) : m_Data(val) 
            {}
            T m_Data;

            const  std::type_info& getType() override
            {
                return typeid(m_Data);
            }
        };

        any_base*  m_AnyImp{nullptr};

        template<class F>
        friend F any_cast(any& obj);

        template<class F>
        friend F any_cast(const any& obj);
    };

    template<class F>
    F any_cast(any& obj)
    {
        if(obj.m_AnyImp->getType() == typeid(F))
        {
            return static_cast<any::any_storage<F>*>(obj.m_AnyImp)->m_Data;
        }
        else
        {
            
        }
    }

    template<class F>
    F any_cast(const any& obj)
    {
    }


}