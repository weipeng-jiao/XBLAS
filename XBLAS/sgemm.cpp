#include<xmmintrin.h>

void sgemm( int k, float *A, int ldA, float *B, int ldB,
		float *C, int ldC )
{
  //加载
  __m128 gamma_0123_0 = _mm128_loadu_ps( &gamma( 0,0 ) );
  __m128 gamma_0123_1 = _mm128_loadu_ps( &gamma( 0,1 ) );
  __m128 gamma_0123_2 = _mm128_loadu_ps( &gamma( 0,2 ) );
  __m128 gamma_0123_3 = _mm128_loadu_ps( &gamma( 0,3 ) );
   	
  for ( int p=0; p<k; p++ )
  {
    
    //加载
    __m128 beta_p_j;
    
    __m128 alpha_0123_p = _mm128_loadu_ps( &alpha( 0,p ) );

    beta_p_j = _mm128_broadcast_ss( &beta( p, 0) );
    
    //向量化
    gamma_0123_0 = _mm128_fmadd_ps( alpha_0123_p, beta_p_j, gamma_0123_0 );
    
    beta_p_j = _mm128_broadcast_ss( &beta( p, 1) );
    gamma_0123_1 = _mm128_fmadd_ps( alpha_0123_p, beta_p_j, gamma_0123_1 );
    beta_p_j = _mm128_broadcast_ss( &beta( p, 2) );
    gamma_0123_2 = _mm128_fmadd_ps( alpha_0123_p, beta_p_j, gamma_0123_2 );
    beta_p_j = _mm128_broadcast_ss( &beta( p, 3) );
    gamma_0123_3 = _mm128_fmadd_ps( alpha_0123_p, beta_p_j, gamma_0123_3 );
  }
  
  /*存储更新的结果*/
  _mm128_storeu_ps( &gamma(0,0), gamma_0123_0 );
  _mm128_storeu_ps( &gamma(0,1), gamma_0123_1 );
  _mm128_storeu_ps( &gamma(0,2), gamma_0123_2 );
  _mm128_storeu_ps( &gamma(0,3), gamma_0123_3 );
}