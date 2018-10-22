<!DOCTYPE html>
<html>

<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>kishorePan</title>
  <link rel="stylesheet" href="https://stackedit.io/style.css" />
</head>

<body class="stackedit">
  <div class="stackedit__left">
    <div class="stackedit__toc">
      
<ul>
<li><a href="#the-partial-pangram-check">The Partial Pangram Check</a></li>
<li><a href="#refactor-9">Refactor 9</a></li>
<li><a href="#refactor-8">Refactor 8</a></li>
<li><a href="#refactor-7">Refactor 7</a></li>
<li><a href="#refactor-6">Refactor 6</a></li>
<li><a href="#refactor-5">Refactor 5</a></li>
<li><a href="#refactor-4">Refactor 4</a></li>
<li><a href="#refactor-3">Refactor 3</a></li>
<li><a href="#refactor-2">Refactor 2</a></li>
<li><a href="#refactor-1">Refactor 1</a></li>
<li><a href="#original">Original</a></li>
</ul>

    </div>
  </div>
  <div class="stackedit__right">
    <div class="stackedit__html">
      <h1 id="the-partial-pangram-check">The Partial Pangram Check</h1>
<h1 id="refactor-9">Refactor 9</h1>
<p>Compare with the alternative code for the same program. Which is better and why?</p>
<pre class=" language-c"><code class="prism  language-c"><span class="token keyword">int</span> <span class="token function">pangram_check</span><span class="token punctuation">(</span><span class="token keyword">const</span> <span class="token keyword">char</span> <span class="token operator">*</span>phrase<span class="token punctuation">)</span> <span class="token punctuation">{</span>
  <span class="token keyword">const</span> <span class="token keyword">char</span> <span class="token operator">*</span>alphabets <span class="token operator">=</span> <span class="token string">"abcdefghijklmnopqrstuvwxyz"</span><span class="token punctuation">;</span>
  <span class="token keyword">if</span> <span class="token punctuation">(</span><span class="token function">is_subset</span><span class="token punctuation">(</span>alphabets<span class="token punctuation">,</span> phrase<span class="token punctuation">)</span><span class="token punctuation">)</span>
    <span class="token keyword">return</span> <span class="token number">1</span><span class="token punctuation">;</span>

  <span class="token keyword">char</span> <span class="token keyword">const</span> pivot <span class="token operator">=</span> <span class="token function">tolower</span><span class="token punctuation">(</span><span class="token operator">*</span>phrase<span class="token punctuation">)</span><span class="token punctuation">;</span>
  <span class="token keyword">const</span> <span class="token keyword">char</span> <span class="token operator">*</span>text <span class="token operator">=</span> phrase<span class="token operator">+</span><span class="token number">1</span><span class="token punctuation">;</span>
  <span class="token keyword">char</span> next<span class="token punctuation">;</span>
  <span class="token keyword">do</span> <span class="token punctuation">{</span>
    next <span class="token operator">=</span> <span class="token function">tolower</span><span class="token punctuation">(</span><span class="token operator">*</span>text<span class="token punctuation">)</span><span class="token punctuation">;</span>
  <span class="token punctuation">}</span> <span class="token keyword">while</span> <span class="token punctuation">(</span>next <span class="token operator">==</span> pivot <span class="token operator">&amp;&amp;</span> <span class="token operator">*</span>text<span class="token operator">++</span><span class="token punctuation">)</span><span class="token punctuation">;</span>

  <span class="token keyword">int</span> direction <span class="token operator">=</span> next <span class="token operator">-</span> pivot<span class="token punctuation">;</span>
  <span class="token keyword">if</span> <span class="token punctuation">(</span><span class="token function">abs</span><span class="token punctuation">(</span>direction<span class="token punctuation">)</span> <span class="token operator">&gt;</span> <span class="token number">1</span><span class="token punctuation">)</span>
    <span class="token keyword">return</span> <span class="token number">0</span><span class="token punctuation">;</span>

  next <span class="token operator">=</span> next <span class="token operator">+</span> direction<span class="token punctuation">;</span>
  <span class="token keyword">char</span> c<span class="token punctuation">;</span>
  <span class="token keyword">while</span> <span class="token punctuation">(</span><span class="token punctuation">(</span>c <span class="token operator">=</span> <span class="token function">tolower</span><span class="token punctuation">(</span><span class="token operator">*</span>text<span class="token operator">++</span><span class="token punctuation">)</span><span class="token punctuation">)</span><span class="token punctuation">)</span> <span class="token punctuation">{</span>
    <span class="token keyword">if</span> <span class="token punctuation">(</span><span class="token function">isalpha</span><span class="token punctuation">(</span>c<span class="token punctuation">)</span><span class="token punctuation">)</span> <span class="token punctuation">{</span>
      <span class="token keyword">if</span> <span class="token punctuation">(</span>direction <span class="token operator">==</span> <span class="token number">1</span><span class="token punctuation">)</span> <span class="token punctuation">{</span> <span class="token comment">// forward partial?</span>
        <span class="token keyword">if</span> <span class="token punctuation">(</span>c <span class="token operator">&lt;</span> pivot <span class="token operator">||</span> c <span class="token operator">&gt;</span> next<span class="token punctuation">)</span>
          <span class="token keyword">return</span> <span class="token number">0</span><span class="token punctuation">;</span>
      <span class="token punctuation">}</span>
      <span class="token keyword">else</span> <span class="token comment">// reverse partial?</span>
        <span class="token keyword">if</span> <span class="token punctuation">(</span>c <span class="token operator">&gt;</span> pivot <span class="token operator">||</span> c <span class="token operator">&lt;</span> next<span class="token punctuation">)</span>
          <span class="token keyword">return</span> <span class="token number">0</span><span class="token punctuation">;</span>
          
      <span class="token keyword">if</span> <span class="token punctuation">(</span>c <span class="token operator">==</span> next<span class="token punctuation">)</span>
        next <span class="token operator">=</span> next <span class="token operator">+</span> direction<span class="token punctuation">;</span>
    <span class="token punctuation">}</span>
  <span class="token punctuation">}</span> <span class="token comment">// end of while loop</span>
  <span class="token keyword">return</span> <span class="token number">1</span><span class="token punctuation">;</span>
<span class="token punctuation">}</span>

</code></pre>
<h1 id="refactor-8">Refactor 8</h1>
<p>Another brilliant refactor, making the logic close to <code>O(1)</code>?</p>
<pre class=" language-c"><code class="prism  language-c"><span class="token keyword">int</span> <span class="token function">pangram_check</span> <span class="token punctuation">(</span><span class="token keyword">const</span> <span class="token keyword">char</span><span class="token operator">*</span> text<span class="token punctuation">)</span> <span class="token punctuation">{</span>
    <span class="token keyword">char</span> <span class="token operator">*</span>seq <span class="token operator">=</span> <span class="token punctuation">(</span><span class="token keyword">char</span> <span class="token operator">*</span><span class="token punctuation">)</span><span class="token function">malloc</span><span class="token punctuation">(</span><span class="token number">27</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
    <span class="token keyword">unsigned</span> <span class="token keyword">int</span> i <span class="token operator">=</span> <span class="token number">0</span><span class="token punctuation">;</span>
    <span class="token keyword">for</span> <span class="token punctuation">(</span><span class="token keyword">char</span> var <span class="token operator">=</span> <span class="token string">'a'</span><span class="token punctuation">;</span> var <span class="token operator">&lt;=</span> <span class="token string">'z'</span><span class="token punctuation">;</span> var<span class="token operator">++</span><span class="token punctuation">)</span>
        <span class="token keyword">if</span> <span class="token punctuation">(</span><span class="token function">strchr</span><span class="token punctuation">(</span>text<span class="token punctuation">,</span> var<span class="token punctuation">)</span> <span class="token operator">||</span> <span class="token function">strchr</span><span class="token punctuation">(</span>text<span class="token punctuation">,</span> <span class="token function">toupper</span><span class="token punctuation">(</span>var<span class="token punctuation">)</span><span class="token punctuation">)</span><span class="token punctuation">)</span>
            seq<span class="token punctuation">[</span>i<span class="token operator">++</span><span class="token punctuation">]</span> <span class="token operator">=</span> var<span class="token punctuation">;</span>
    <span class="token keyword">if</span> <span class="token punctuation">(</span>i <span class="token operator">==</span> <span class="token number">26</span><span class="token punctuation">)</span>
        <span class="token keyword">return</span> <span class="token number">1</span><span class="token punctuation">;</span>

    <span class="token keyword">const</span> <span class="token keyword">char</span> <span class="token operator">*</span>alphaseq <span class="token operator">=</span> 
        <span class="token string">"abcdefghijklmnopqrstuvwxyzyxwvutsrqponmlkjihgfedcba"</span><span class="token punctuation">;</span>
    <span class="token keyword">return</span> <span class="token function">strstr</span><span class="token punctuation">(</span>alphaseq<span class="token punctuation">,</span> seq<span class="token punctuation">)</span><span class="token operator">?</span> <span class="token number">1</span> <span class="token punctuation">:</span> <span class="token number">0</span><span class="token punctuation">;</span>
    
<span class="token punctuation">}</span>

</code></pre>
<h1 id="refactor-7">Refactor 7</h1>
<ul>
<li>The original ~60 line program now reduced to about ~20 lines - a 66% reduction!</li>
<li>The integrated <code>pangram_check()</code> algorithm is quite efficient and ready for porting to C++</li>
</ul>
<pre class=" language-c"><code class="prism  language-c">
<span class="token keyword">int</span> <span class="token function">pangram_check</span> <span class="token punctuation">(</span><span class="token keyword">const</span> <span class="token keyword">char</span><span class="token operator">*</span> text<span class="token punctuation">)</span> <span class="token punctuation">{</span>
    <span class="token keyword">char</span> <span class="token operator">*</span>seq <span class="token operator">=</span> <span class="token punctuation">(</span><span class="token keyword">char</span> <span class="token operator">*</span><span class="token punctuation">)</span><span class="token function">malloc</span><span class="token punctuation">(</span><span class="token number">27</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
    <span class="token keyword">unsigned</span> <span class="token keyword">int</span> i <span class="token operator">=</span> <span class="token number">0</span><span class="token punctuation">;</span>
    <span class="token keyword">while</span> <span class="token punctuation">(</span><span class="token operator">*</span>text<span class="token punctuation">)</span>
    <span class="token punctuation">{</span>
        <span class="token keyword">char</span> c <span class="token operator">=</span> <span class="token function">tolower</span><span class="token punctuation">(</span><span class="token operator">*</span>text<span class="token punctuation">)</span><span class="token punctuation">;</span>
        <span class="token keyword">if</span> <span class="token punctuation">(</span><span class="token function">isalnum</span><span class="token punctuation">(</span>c<span class="token punctuation">)</span> <span class="token operator">&amp;&amp;</span> <span class="token operator">!</span><span class="token function">strchr</span><span class="token punctuation">(</span>seq<span class="token punctuation">,</span> c<span class="token punctuation">)</span><span class="token punctuation">)</span>
            seq<span class="token punctuation">[</span>i<span class="token operator">++</span><span class="token punctuation">]</span> <span class="token operator">=</span> <span class="token function">tolower</span><span class="token punctuation">(</span><span class="token operator">*</span>text<span class="token punctuation">)</span><span class="token punctuation">;</span>
        text<span class="token operator">++</span><span class="token punctuation">;</span>
    <span class="token punctuation">}</span>
    <span class="token keyword">if</span> <span class="token punctuation">(</span><span class="token function">strlen</span><span class="token punctuation">(</span>seq<span class="token punctuation">)</span> <span class="token operator">==</span> <span class="token number">26</span><span class="token punctuation">)</span>
        <span class="token keyword">return</span> <span class="token number">1</span><span class="token punctuation">;</span>

    <span class="token keyword">const</span> <span class="token keyword">char</span> <span class="token operator">*</span>alphaseq <span class="token operator">=</span> 
        <span class="token string">"abcdefghijklmnopqrstuvwxyzyxwvutsrqponmlkjihgfedcba"</span><span class="token punctuation">;</span>
    <span class="token keyword">return</span> <span class="token function">strstr</span><span class="token punctuation">(</span>alphaseq<span class="token punctuation">,</span> seq<span class="token punctuation">)</span><span class="token operator">?</span> <span class="token number">1</span> <span class="token punctuation">:</span> <span class="token number">0</span><span class="token punctuation">;</span>   
<span class="token punctuation">}</span>

</code></pre>
<h1 id="refactor-6">Refactor 6</h1>
<p>The main function <code>pangram_check()</code> had a bug where it was prematurely returning a <code>0</code> for strings that were valid partial pangrams but of length longer than 26. The outer <code>if</code> statement was removed and the rest of the code was refactored.</p>
<ul>
<li>in pangram_check, <code>strchr</code> is used twice, instead why not have a strchr which is case-insensitive?</li>
</ul>
<pre class=" language-c"><code class="prism  language-c"><span class="token keyword">int</span> <span class="token function">pangram_check</span> <span class="token punctuation">(</span><span class="token keyword">const</span> <span class="token keyword">char</span><span class="token operator">*</span> text<span class="token punctuation">)</span> <span class="token punctuation">{</span>
    
    <span class="token keyword">int</span> count <span class="token operator">=</span> <span class="token number">0</span><span class="token punctuation">;</span>
    <span class="token keyword">for</span> <span class="token punctuation">(</span><span class="token keyword">char</span> var <span class="token operator">=</span> <span class="token string">'a'</span><span class="token punctuation">;</span> var <span class="token operator">&lt;=</span> <span class="token string">'z'</span><span class="token punctuation">;</span> var<span class="token operator">++</span><span class="token punctuation">)</span>
        <span class="token keyword">if</span> <span class="token punctuation">(</span><span class="token function">strchr</span><span class="token punctuation">(</span>text<span class="token punctuation">,</span> var<span class="token punctuation">)</span> <span class="token operator">||</span> <span class="token function">strchr</span><span class="token punctuation">(</span>text<span class="token punctuation">,</span> <span class="token function">toupper</span><span class="token punctuation">(</span>var<span class="token punctuation">)</span><span class="token punctuation">)</span><span class="token punctuation">)</span>
            count<span class="token operator">++</span><span class="token punctuation">;</span>
    <span class="token keyword">if</span> <span class="token punctuation">(</span>count <span class="token operator">==</span> <span class="token number">26</span><span class="token punctuation">)</span> <span class="token keyword">return</span> <span class="token number">1</span><span class="token punctuation">;</span>

    <span class="token keyword">return</span> <span class="token function">partial_pangram_check</span><span class="token punctuation">(</span>text<span class="token punctuation">)</span><span class="token punctuation">;</span>
<span class="token punctuation">}</span>

</code></pre>
<h1 id="refactor-5">Refactor 5</h1>
<p>The final chisel: replaced <code>not_in_seq()</code> function with <code>strchr</code> function.</p>
<pre class=" language-c"><code class="prism  language-c"><span class="token keyword">int</span> <span class="token function">partial_pangram_check</span><span class="token punctuation">(</span><span class="token keyword">const</span> <span class="token keyword">char</span> <span class="token operator">*</span>text<span class="token punctuation">)</span><span class="token punctuation">{</span>
    <span class="token keyword">char</span> <span class="token operator">*</span>seq <span class="token operator">=</span> <span class="token punctuation">(</span><span class="token keyword">char</span> <span class="token operator">*</span><span class="token punctuation">)</span><span class="token function">malloc</span><span class="token punctuation">(</span><span class="token number">25</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
    <span class="token keyword">const</span> <span class="token keyword">char</span> <span class="token operator">*</span>alphaseq <span class="token operator">=</span> 
        <span class="token string">"abcdefghijklmnopqrstuvwxyzyxwvutsrqponmlkjihgfedcba"</span><span class="token punctuation">;</span>
    
    <span class="token keyword">unsigned</span> <span class="token keyword">int</span> i <span class="token operator">=</span> <span class="token number">0</span><span class="token punctuation">;</span>
    <span class="token keyword">while</span> <span class="token punctuation">(</span><span class="token operator">*</span>text<span class="token punctuation">)</span>
    <span class="token punctuation">{</span>
        <span class="token keyword">char</span> c <span class="token operator">=</span> <span class="token function">tolower</span><span class="token punctuation">(</span><span class="token operator">*</span>text<span class="token punctuation">)</span><span class="token punctuation">;</span>
        <span class="token keyword">if</span> <span class="token punctuation">(</span><span class="token function">isalnum</span><span class="token punctuation">(</span>c<span class="token punctuation">)</span> <span class="token operator">&amp;&amp;</span> <span class="token operator">!</span><span class="token function">strchr</span><span class="token punctuation">(</span>seq<span class="token punctuation">,</span> c<span class="token punctuation">)</span><span class="token punctuation">)</span>
            seq<span class="token punctuation">[</span>i<span class="token operator">++</span><span class="token punctuation">]</span> <span class="token operator">=</span> <span class="token function">tolower</span><span class="token punctuation">(</span><span class="token operator">*</span>text<span class="token punctuation">)</span><span class="token punctuation">;</span>
        text<span class="token operator">++</span><span class="token punctuation">;</span>
    <span class="token punctuation">}</span>
    <span class="token keyword">return</span> <span class="token function">strstr</span><span class="token punctuation">(</span>alphaseq<span class="token punctuation">,</span> seq<span class="token punctuation">)</span><span class="token operator">?</span> <span class="token number">1</span> <span class="token punctuation">:</span> <span class="token number">0</span><span class="token punctuation">;</span>
<span class="token punctuation">}</span>

</code></pre>
<h1 id="refactor-4">Refactor 4</h1>
<p>Using <code>strstr</code> to further reduce code length</p>
<pre class=" language-c"><code class="prism  language-c"><span class="token keyword">int</span> <span class="token function">partial_pangram_check</span><span class="token punctuation">(</span><span class="token keyword">const</span> <span class="token keyword">char</span> <span class="token operator">*</span>text<span class="token punctuation">)</span><span class="token punctuation">{</span>
    <span class="token keyword">char</span> <span class="token operator">*</span>seq <span class="token operator">=</span> <span class="token punctuation">(</span><span class="token keyword">char</span> <span class="token operator">*</span><span class="token punctuation">)</span><span class="token function">malloc</span><span class="token punctuation">(</span><span class="token number">25</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
    <span class="token keyword">const</span> <span class="token keyword">char</span> <span class="token operator">*</span>alphaseq <span class="token operator">=</span> 
        <span class="token string">"abcdefghijklmnopqrstuvwxyzyxwvutsrqponmlkjihgfedcba"</span><span class="token punctuation">;</span>
    
    <span class="token keyword">unsigned</span> <span class="token keyword">int</span> i <span class="token operator">=</span> <span class="token number">0</span><span class="token punctuation">;</span>
    <span class="token keyword">while</span> <span class="token punctuation">(</span><span class="token operator">*</span>text<span class="token punctuation">)</span>
    <span class="token punctuation">{</span>
        <span class="token keyword">char</span> c <span class="token operator">=</span> <span class="token function">tolower</span><span class="token punctuation">(</span><span class="token operator">*</span>text<span class="token punctuation">)</span><span class="token punctuation">;</span>
        <span class="token keyword">if</span> <span class="token punctuation">(</span><span class="token function">isalnum</span><span class="token punctuation">(</span>c<span class="token punctuation">)</span> <span class="token operator">&amp;&amp;</span> <span class="token function">not_in_seq</span><span class="token punctuation">(</span>c<span class="token punctuation">,</span> seq<span class="token punctuation">)</span><span class="token punctuation">)</span>
            seq<span class="token punctuation">[</span>i<span class="token operator">++</span><span class="token punctuation">]</span> <span class="token operator">=</span> <span class="token function">tolower</span><span class="token punctuation">(</span><span class="token operator">*</span>text<span class="token punctuation">)</span><span class="token punctuation">;</span>
        text<span class="token operator">++</span><span class="token punctuation">;</span>
    <span class="token punctuation">}</span>
    <span class="token keyword">return</span> <span class="token function">strstr</span><span class="token punctuation">(</span>alphaseq<span class="token punctuation">,</span> seq<span class="token punctuation">)</span><span class="token operator">?</span> <span class="token number">1</span> <span class="token punctuation">:</span> <span class="token number">0</span><span class="token punctuation">;</span>
<span class="token punctuation">}</span>
</code></pre>
<h1 id="refactor-3">Refactor 3</h1>
<p>Refactored out the variable <code>partial_perfect</code></p>
<pre class=" language-c"><code class="prism  language-c"><span class="token keyword">int</span> <span class="token function">partial_pangram_check</span><span class="token punctuation">(</span><span class="token keyword">const</span> <span class="token keyword">char</span> <span class="token operator">*</span>text<span class="token punctuation">)</span><span class="token punctuation">{</span>
    <span class="token keyword">char</span> <span class="token operator">*</span>seq <span class="token operator">=</span> <span class="token punctuation">(</span><span class="token keyword">char</span> <span class="token operator">*</span><span class="token punctuation">)</span><span class="token function">malloc</span><span class="token punctuation">(</span><span class="token number">25</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
    
    <span class="token keyword">unsigned</span> <span class="token keyword">int</span> i <span class="token operator">=</span> <span class="token number">0</span><span class="token punctuation">;</span>
    <span class="token keyword">while</span> <span class="token punctuation">(</span><span class="token operator">*</span>text<span class="token punctuation">)</span>
    <span class="token punctuation">{</span>
        <span class="token keyword">char</span> c <span class="token operator">=</span> <span class="token function">tolower</span><span class="token punctuation">(</span><span class="token operator">*</span>text<span class="token punctuation">)</span><span class="token punctuation">;</span>
        <span class="token keyword">if</span> <span class="token punctuation">(</span><span class="token function">isalnum</span><span class="token punctuation">(</span>c<span class="token punctuation">)</span> <span class="token operator">&amp;&amp;</span> <span class="token function">not_in_seq</span><span class="token punctuation">(</span>c<span class="token punctuation">,</span> seq<span class="token punctuation">)</span><span class="token punctuation">)</span>
            seq<span class="token punctuation">[</span>i<span class="token operator">++</span><span class="token punctuation">]</span> <span class="token operator">=</span> <span class="token function">tolower</span><span class="token punctuation">(</span><span class="token operator">*</span>text<span class="token punctuation">)</span><span class="token punctuation">;</span>
        text<span class="token operator">++</span><span class="token punctuation">;</span>
    <span class="token punctuation">}</span>
    i <span class="token operator">=</span> <span class="token number">0</span><span class="token punctuation">;</span>
    <span class="token keyword">for</span> <span class="token punctuation">(</span><span class="token punctuation">;</span> i <span class="token operator">&lt;</span> <span class="token function">strlen</span><span class="token punctuation">(</span>seq<span class="token punctuation">)</span><span class="token operator">-</span><span class="token number">1</span><span class="token punctuation">;</span> i<span class="token operator">++</span><span class="token punctuation">)</span>
        <span class="token keyword">if</span> <span class="token punctuation">(</span><span class="token function">abs</span><span class="token punctuation">(</span>seq<span class="token punctuation">[</span>i<span class="token punctuation">]</span><span class="token operator">-</span>seq<span class="token punctuation">[</span>i<span class="token operator">+</span><span class="token number">1</span><span class="token punctuation">]</span><span class="token punctuation">)</span> <span class="token operator">!=</span> <span class="token number">1</span><span class="token punctuation">)</span>
            <span class="token keyword">return</span> <span class="token number">0</span><span class="token punctuation">;</span>
    <span class="token keyword">return</span> <span class="token number">1</span><span class="token punctuation">;</span>
<span class="token punctuation">}</span>

</code></pre>
<h1 id="refactor-2">Refactor 2</h1>
<p>Storing the sequence in lowercase</p>
<pre class=" language-c"><code class="prism  language-c"><span class="token keyword">int</span> <span class="token function">partial_pangram_check</span><span class="token punctuation">(</span><span class="token keyword">const</span> <span class="token keyword">char</span> <span class="token operator">*</span>text<span class="token punctuation">)</span><span class="token punctuation">{</span>
    <span class="token keyword">char</span> <span class="token operator">*</span>seq <span class="token operator">=</span> <span class="token punctuation">(</span><span class="token keyword">char</span> <span class="token operator">*</span><span class="token punctuation">)</span><span class="token function">malloc</span><span class="token punctuation">(</span><span class="token number">25</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
    
    <span class="token keyword">unsigned</span> <span class="token keyword">int</span> i <span class="token operator">=</span> <span class="token number">0</span><span class="token punctuation">,</span> partial_perfect <span class="token operator">=</span> <span class="token number">0</span><span class="token punctuation">;</span>
    <span class="token keyword">while</span> <span class="token punctuation">(</span><span class="token operator">*</span>text<span class="token punctuation">)</span>
    <span class="token punctuation">{</span>
        <span class="token keyword">char</span> c <span class="token operator">=</span> <span class="token function">tolower</span><span class="token punctuation">(</span><span class="token operator">*</span>text<span class="token punctuation">)</span><span class="token punctuation">;</span>
        <span class="token keyword">if</span> <span class="token punctuation">(</span><span class="token function">isalnum</span><span class="token punctuation">(</span>c<span class="token punctuation">)</span> <span class="token operator">&amp;&amp;</span> <span class="token function">not_in_seq</span><span class="token punctuation">(</span>c<span class="token punctuation">,</span> seq<span class="token punctuation">)</span><span class="token punctuation">)</span>
            seq<span class="token punctuation">[</span>i<span class="token operator">++</span><span class="token punctuation">]</span> <span class="token operator">=</span> <span class="token function">tolower</span><span class="token punctuation">(</span><span class="token operator">*</span>text<span class="token punctuation">)</span><span class="token punctuation">;</span>
        text<span class="token operator">++</span><span class="token punctuation">;</span>
    <span class="token punctuation">}</span>
    i <span class="token operator">=</span> <span class="token number">0</span><span class="token punctuation">;</span>
    <span class="token keyword">for</span> <span class="token punctuation">(</span><span class="token punctuation">;</span> i <span class="token operator">&lt;</span> <span class="token function">strlen</span><span class="token punctuation">(</span>seq<span class="token punctuation">)</span><span class="token operator">-</span><span class="token number">1</span><span class="token punctuation">;</span> i<span class="token operator">++</span><span class="token punctuation">)</span>
    <span class="token punctuation">{</span>
        <span class="token keyword">if</span> <span class="token punctuation">(</span><span class="token function">abs</span><span class="token punctuation">(</span>seq<span class="token punctuation">[</span>i<span class="token punctuation">]</span><span class="token operator">-</span>seq<span class="token punctuation">[</span>i<span class="token operator">+</span><span class="token number">1</span><span class="token punctuation">]</span><span class="token punctuation">)</span> <span class="token operator">==</span> <span class="token number">1</span><span class="token punctuation">)</span>
            partial_perfect<span class="token operator">++</span><span class="token punctuation">;</span>
    <span class="token punctuation">}</span>
    <span class="token keyword">if</span> <span class="token punctuation">(</span>partial_perfect <span class="token operator">==</span> <span class="token function">strlen</span><span class="token punctuation">(</span>seq<span class="token punctuation">)</span><span class="token operator">-</span><span class="token number">1</span><span class="token punctuation">)</span>
        <span class="token keyword">return</span> <span class="token number">1</span><span class="token punctuation">;</span>
    <span class="token keyword">else</span>
        <span class="token keyword">return</span> <span class="token number">0</span><span class="token punctuation">;</span>
<span class="token punctuation">}</span>

</code></pre>
<h1 id="refactor-1">Refactor 1</h1>
<p>Replacing <code>new</code> with <code>malloc</code> to make it a pure C version</p>
<pre class=" language-c"><code class="prism  language-c">    <span class="token comment">//char *seq = new char[20]();</span>
    <span class="token keyword">char</span> <span class="token operator">*</span>seq <span class="token operator">=</span> <span class="token punctuation">(</span><span class="token keyword">char</span> <span class="token operator">*</span><span class="token punctuation">)</span><span class="token function">malloc</span><span class="token punctuation">(</span><span class="token number">25</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
</code></pre>
<h1 id="original">Original</h1>
<pre class=" language-cpp"><code class="prism  language-cpp"><span class="token macro property">#<span class="token directive keyword">include</span> <span class="token string">"iostream"</span></span>
<span class="token macro property">#<span class="token directive keyword">include</span> <span class="token string">"string.h"</span></span>
<span class="token macro property">#<span class="token directive keyword">include</span> <span class="token string">"cctype"</span></span>
<span class="token keyword">using</span> <span class="token keyword">namespace</span> std<span class="token punctuation">;</span>


<span class="token keyword">int</span> <span class="token function">not_in_seq</span><span class="token punctuation">(</span><span class="token keyword">char</span> a<span class="token punctuation">,</span> <span class="token keyword">const</span> <span class="token keyword">char</span> <span class="token operator">*</span>seq<span class="token punctuation">)</span>
<span class="token punctuation">{</span>
    <span class="token keyword">unsigned</span> <span class="token keyword">int</span> count <span class="token operator">=</span> <span class="token number">0</span><span class="token punctuation">,</span> i <span class="token operator">=</span> <span class="token number">0</span><span class="token punctuation">;</span>
    <span class="token keyword">while</span> <span class="token punctuation">(</span>i <span class="token operator">&lt;</span> <span class="token function">strlen</span><span class="token punctuation">(</span>seq<span class="token punctuation">)</span><span class="token punctuation">)</span>
    <span class="token punctuation">{</span>
        <span class="token keyword">if</span> <span class="token punctuation">(</span>a <span class="token operator">!=</span> seq<span class="token punctuation">[</span>i<span class="token punctuation">]</span><span class="token punctuation">)</span>
            count<span class="token operator">++</span><span class="token punctuation">;</span>
        i<span class="token operator">++</span><span class="token punctuation">;</span>
    <span class="token punctuation">}</span>
    <span class="token keyword">if</span> <span class="token punctuation">(</span>count <span class="token operator">==</span> <span class="token function">strlen</span><span class="token punctuation">(</span>seq<span class="token punctuation">)</span><span class="token punctuation">)</span>
        <span class="token keyword">return</span> <span class="token number">1</span><span class="token punctuation">;</span>
    <span class="token keyword">else</span>
        <span class="token keyword">return</span> <span class="token number">0</span><span class="token punctuation">;</span>
<span class="token punctuation">}</span>


<span class="token keyword">int</span> <span class="token function">partial_pangram_check</span><span class="token punctuation">(</span><span class="token keyword">const</span> <span class="token keyword">char</span> <span class="token operator">*</span>text<span class="token punctuation">)</span><span class="token punctuation">{</span>
    <span class="token keyword">char</span> <span class="token operator">*</span>seq <span class="token operator">=</span> <span class="token keyword">new</span> <span class="token keyword">char</span><span class="token punctuation">[</span><span class="token number">20</span><span class="token punctuation">]</span><span class="token punctuation">(</span><span class="token punctuation">)</span><span class="token punctuation">;</span>
    <span class="token keyword">unsigned</span> <span class="token keyword">int</span> i <span class="token operator">=</span> <span class="token number">0</span><span class="token punctuation">,</span> partial_perfect <span class="token operator">=</span> <span class="token number">0</span><span class="token punctuation">;</span>
    seq<span class="token punctuation">[</span>i<span class="token operator">++</span><span class="token punctuation">]</span> <span class="token operator">=</span> <span class="token operator">*</span>text<span class="token punctuation">;</span>
    text<span class="token operator">++</span><span class="token punctuation">;</span>
    <span class="token keyword">while</span> <span class="token punctuation">(</span><span class="token operator">*</span>text<span class="token punctuation">)</span>
    <span class="token punctuation">{</span>
        <span class="token keyword">if</span> <span class="token punctuation">(</span><span class="token operator">!</span><span class="token function">isblank</span><span class="token punctuation">(</span><span class="token operator">*</span>text<span class="token punctuation">)</span> <span class="token operator">&amp;&amp;</span> <span class="token function">not_in_seq</span><span class="token punctuation">(</span><span class="token operator">*</span>text<span class="token punctuation">,</span> seq<span class="token punctuation">)</span><span class="token punctuation">)</span>
            seq<span class="token punctuation">[</span>i<span class="token operator">++</span><span class="token punctuation">]</span> <span class="token operator">=</span> <span class="token operator">*</span>text<span class="token punctuation">;</span>
        text<span class="token operator">++</span><span class="token punctuation">;</span>
    <span class="token punctuation">}</span>
    i <span class="token operator">=</span> <span class="token number">0</span><span class="token punctuation">;</span>
    <span class="token keyword">for</span> <span class="token punctuation">(</span><span class="token punctuation">;</span> i <span class="token operator">&lt;</span> <span class="token function">strlen</span><span class="token punctuation">(</span>seq<span class="token punctuation">)</span><span class="token operator">-</span><span class="token number">1</span><span class="token punctuation">;</span> i<span class="token operator">++</span><span class="token punctuation">)</span>
    <span class="token punctuation">{</span>
        <span class="token keyword">if</span> <span class="token punctuation">(</span><span class="token punctuation">(</span><span class="token function">abs</span><span class="token punctuation">(</span>seq<span class="token punctuation">[</span>i<span class="token punctuation">]</span><span class="token operator">-</span>seq<span class="token punctuation">[</span>i<span class="token operator">+</span><span class="token number">1</span><span class="token punctuation">]</span><span class="token punctuation">)</span> <span class="token operator">==</span> <span class="token number">1</span><span class="token punctuation">)</span> <span class="token operator">||</span> <span class="token punctuation">(</span><span class="token function">abs</span><span class="token punctuation">(</span>seq<span class="token punctuation">[</span>i<span class="token punctuation">]</span><span class="token operator">-</span>seq<span class="token punctuation">[</span>i<span class="token operator">+</span><span class="token number">1</span><span class="token punctuation">]</span><span class="token punctuation">)</span> <span class="token operator">==</span> <span class="token number">33</span><span class="token punctuation">)</span> <span class="token operator">||</span> <span class="token punctuation">(</span><span class="token function">abs</span><span class="token punctuation">(</span>seq<span class="token punctuation">[</span>i<span class="token punctuation">]</span><span class="token operator">-</span>seq<span class="token punctuation">[</span>i<span class="token operator">+</span><span class="token number">1</span><span class="token punctuation">]</span><span class="token punctuation">)</span> <span class="token operator">==</span> <span class="token number">31</span><span class="token punctuation">)</span><span class="token punctuation">)</span>
            partial_perfect<span class="token operator">++</span><span class="token punctuation">;</span>
    <span class="token punctuation">}</span>
    <span class="token keyword">if</span> <span class="token punctuation">(</span>partial_perfect <span class="token operator">==</span> <span class="token function">strlen</span><span class="token punctuation">(</span>seq<span class="token punctuation">)</span><span class="token operator">-</span><span class="token number">1</span><span class="token punctuation">)</span>
        <span class="token keyword">return</span> <span class="token number">1</span><span class="token punctuation">;</span>
    <span class="token keyword">else</span>
        <span class="token keyword">return</span> <span class="token number">0</span><span class="token punctuation">;</span>
<span class="token punctuation">}</span>

<span class="token keyword">int</span> <span class="token function">pangram_check</span> <span class="token punctuation">(</span><span class="token keyword">const</span> <span class="token keyword">char</span><span class="token operator">*</span> text<span class="token punctuation">)</span> <span class="token punctuation">{</span>
    <span class="token keyword">unsigned</span> <span class="token keyword">int</span> var <span class="token operator">=</span> <span class="token number">65</span><span class="token punctuation">,</span> count <span class="token operator">=</span> <span class="token number">0</span><span class="token punctuation">,</span> i <span class="token operator">=</span> <span class="token number">0</span><span class="token punctuation">;</span>
    <span class="token keyword">if</span> <span class="token punctuation">(</span><span class="token function">strlen</span><span class="token punctuation">(</span>text<span class="token punctuation">)</span> <span class="token operator">&gt;=</span> <span class="token number">26</span><span class="token punctuation">)</span>
    <span class="token punctuation">{</span>
        <span class="token keyword">for</span> <span class="token punctuation">(</span><span class="token punctuation">;</span> i <span class="token operator">&lt;</span> <span class="token function">strlen</span><span class="token punctuation">(</span>text<span class="token punctuation">)</span><span class="token punctuation">;</span> i<span class="token operator">++</span><span class="token punctuation">)</span>
        <span class="token punctuation">{</span>
            <span class="token keyword">if</span> <span class="token punctuation">(</span><span class="token punctuation">(</span><span class="token function">strchr</span><span class="token punctuation">(</span>text<span class="token punctuation">,</span> var<span class="token punctuation">)</span> <span class="token operator">||</span> <span class="token function">strchr</span><span class="token punctuation">(</span>text<span class="token punctuation">,</span> var<span class="token operator">+</span><span class="token number">32</span><span class="token punctuation">)</span><span class="token punctuation">)</span> <span class="token operator">&amp;&amp;</span> var <span class="token operator">&lt;=</span> <span class="token number">90</span><span class="token punctuation">)</span>
                count<span class="token operator">++</span><span class="token punctuation">;</span>
            var<span class="token operator">++</span><span class="token punctuation">;</span>
        <span class="token punctuation">}</span>
        <span class="token keyword">if</span> <span class="token punctuation">(</span>count <span class="token operator">==</span> <span class="token number">26</span><span class="token punctuation">)</span>
            <span class="token keyword">return</span> <span class="token number">1</span><span class="token punctuation">;</span>
        <span class="token keyword">else</span>
            <span class="token keyword">return</span> <span class="token number">0</span><span class="token punctuation">;</span>
    <span class="token punctuation">}</span>
    <span class="token keyword">else</span>
        <span class="token keyword">return</span> <span class="token function">partial_pangram_check</span><span class="token punctuation">(</span>text<span class="token punctuation">)</span><span class="token punctuation">;</span>
<span class="token punctuation">}</span>

</code></pre>

    </div>
  </div>
</body>

</html>
