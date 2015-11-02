/*
 ** Thread.h for SL
 **
 ** Made by lucas stefas
 ** Login   stefas_l
 **
 ** Started on 31/07/13 19:39 2013 by lucas stefas
 */

/**
 * @file
 *
 * @ingroup PortableThread
 *
 * @brief simple Thread surcharge.
 */

#ifndef		__Thread_H__
#define		__Thread_H__

#ifdef		__cplusplus
extern "C" {
#endif
	
#include <RetroEngine/RetroType.h>
	
	/**
	 * @defgroup PortableThread PortableThread
	 *
	 * @ingroup UpperLevelGroup
	 *
	 * @brief simple Thread surcharge.
	 *
	 * @{
	 */
	
	/**
	 * @defgroup PortableThreadType Type
	 *
	 * @ingroup PortableThread
	 *
	 * @brief All the type used to make a thread portable.
	 * The ThreadStruct, ThreadStructList, PortableThread aren't
	 * that important, but you will use them but doesn't need
	 * to know what their is inside.
	 * @{
	 */
	
#if defined (Windows)
	
#include					<Windows.h>
	
	/**
	 * @brief For having the same on all os.
	 *
	 * just a typedef for having the same thing on windows and UNIX.
	 */
	typedef	DWORD (WINAPI *ptrThread)(LPVOID);
	
	/**
	 * @brief For having the same on all os.
	 *
	 * just a typedef for having the same thing on windows and UNIX.
	 */
	typedef LPVOID			ThreadParam;
	
	/**
	 * @brief For having the same on all os.
	 *
	 * just a typedef for having the same thing on windows and UNIX.
	 */
	typedef HANDLE			ThreadHandler;
	
	/**
	 * @brief For having the same on all os.
	 *
	 * just a typedef for having the same thing on windows and UNIX.
	 */
	typedef DWORD			ThreadReturn;
	
	/**
	 * @brief For having the same on all os.
	 *
	 * just a typedef for having the same thing on windows and UNIX.
	 */
#define	ThreadRetVal		DWORD WINAPI
	
	/**
	 * @brief For having the same on all os.
	 *
	 * just a typedef for having the same thing on windows and UNIX.
	 */
#define CREATETHREAD(func, thread, param)	thread = CreateThread(NULL, 0, func, param, 0, NULL);
	
#else
	
#include <pthread.h>
#include <unistd.h>
	
	/**
	 * @brief For having the same on all os.
	 *
	 * just a typedef for having the same thing on windows and UNIX.
	 */
	typedef	void* (*ptrThread)(void *);
	
	/**
	 * @brief For having the same on all os.
	 *
	 * just a typedef for having the same thing on windows and UNIX.
	 */
	typedef void*		ThreadParam;
	
	/**
	 * @brief For having the same on all os.
	 *
	 * just a typedef for having the same thing on windows and UNIX.
	 */
	typedef pthread_t	ThreadHandler;
	
	/**
	 * @brief For having the same on all os.
	 *
	 * just a typedef for having the same thing on windows and UNIX.
	 */
	typedef void*		ThreadReturn;
	
	/**
	 * @brief For having the same on all os.
	 *
	 * just a typedef for having the same thing on windows and UNIX.
	 */
#define	ThreadRetVal	void*
	
	/**
	 * @brief For having the same on all os.
	 *
	 * just a typedef for having the same thing on windows and UNIX.
	 */
#define CREATETHREAD(func, thread, param)		pthread_create(&thread, NULL, func, param);
	
#endif
	
	/**
	 * @brief Basic thread structure.
	 *
	 * A thread structur witch retain the thread function,
	 * parameter and later his return value.
	 */
	typedef struct			ThreadStruct
	{
		/**
		 * @brief The thread function.
		 */
		ptrThread			func;
		
		/**
		 * @brief The thread parameter.
		 */
		ThreadParam			param;
		
		/**
		 * @brief The thread handler to manipulate it.
		 */
		ThreadHandler		handler;
		
		/**
		 * @brief The thread return value.
		 */
		ThreadReturn		ret;
	}						ThreadStruct;
	
	typedef struct		ThreadStructList
	{
		ThreadStruct			data;
		size_t			num;
		struct ThreadStructList	*next;
	}					ThreadStructList;
	
	/**
	 * @brief Nothing.
	 *
	 * No, realy, nothing.
	 */
	typedef struct			PortableThread
	{
		/**
		 * @brief All your thread.
		 */
		ThreadStructList	lThread;
	}						PortableThread;
	
	/** @} */
	
	/* Thread.c */
	
	/**
	 * @defgroup PortableThreadFunc Function
	 *
	 * @ingroup PortableThread
	 *
	 * @brief All the function used to work with a thread portable.
	 * 
	 * @{
	 */
	
	/**
	 * @brief create a ready to use PortableThread.
	 *
	 * @retval A ready to use PortableThread.
	 */
	PortableThread*			newPortableThread();
	
	/**
	 * @brief Add A new thread to the list but don't run it.
	 *
	 * @param[in] func The function to run in a thread.
	 * @param[in] param The thread parameter.
	 * @param[in, out] pt The PortableThread to handle all this.
	 * @retval An ID to retrieve this thread.
	 */
	unsigned int			addThread(ptrThread func, ThreadParam param, PortableThread* pt);
	
	/**
	 * @brief Run all your thread.
	 *
	 * @param[in, out] pt The PortableThread to handle all this.
	 * @retval On succes, return False.
	 */
	RetroBool					runAllThread(PortableThread* pt);
	
	/**
	 * @brief Wait for the end of all your thread.
	 *
	 * @param[in, out] pt The PortableThread to handle all this.
	 * @retval On succes, return False.
	 */
	RetroBool					waitAllThread(PortableThread* pt);
	
	/**
	 * @brief Wait for the end of a specific thread.
	 *
	 * @param[in] threadnum The Id of you specific thread, returned by addThread.
	 * @param[in, out] pt The PortableThread to handle all this.
	 * @retval On succes, return False.
	 * @see addThread.
	 */
	RetroBool					waitAThread(unsigned int threadnum, PortableThread* pt);
	
	/* Thread2.c */
	
	/**
	 * @brief Retrieve the value returned by a thread.
	 *
	 * @param[in] id The id of the thread.
	 * @param[in, out] pt The PortableThread to handle all this.
	 * @retval The return value of the thread.
	 */
	ThreadRetVal getThreadRetVal(int id, PortableThread* pt);
	
	/**
	 * @brief Remove a thread.
	 *
	 * @param[in] id The id of the thread.
	 * @param[in, out] pt The PortableThread to handle all this.
	 */
	void removeThread(int id, PortableThread* pt);
	
	/**
	 * @brief Remove all the thread previousli put in the portableThread object.
	 *
	 * @param[in, out] pt The PortableThread to handle all this.
	 */
	void removeAllThread(PortableThread* pt);
	
	/**
	 * @brief Delete the thread handler and set his variable to NULL.
	 *
	 * @param[in, out] pt The PortableThread to handle all this.
	 */
	void deleteThread(PortableThread** pt);

	/** @} */
	
	/** @} */
	
	
#ifdef		__cplusplus
}
#endif

#endif
