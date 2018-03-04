---


---

<h2 id="stringcopy">stringCopy</h2>
<p>Create a function <code>stringcpy</code> that takes two parameters: an <code>dest</code> (character pointer) and a <code>src</code> (const char pointer).</p>
<p>Copy the contents from <code>src</code> to the <code>dest</code>ination.</p>
<h3 id="required-definitions">Required definitions</h3>
<ul>
<li>Define three versions of <code>stringcpy</code> function as <code>stringcpy1()</code> (using array subscripting), <code>stringcpy2()</code> (using pointers) ,  <code>stringcpy3</code> - the most professional version and <code>stringcpy4</code> as a single and simple one line function.</li>
<li>Define a suitable C program with a <code>main</code> function to call the <code>strcpy</code> function after getting the required source destination from stdin.</li>
<li>The given <code>main</code> function must not be edited. Use it as it has been provided, otherwise the test cases may not pass.</li>
</ul>
<h3 id="example">Example</h3>
<p>input: <code>abcde</code><br>
output:  <code>abcde</code></p>
<p>input: <code>copy this</code><br>
output: <code>copy this</code></p>
<h2 id="solution">Solution</h2>
<pre class=" language-c"><code class="prism  language-c">
<span class="token macro property">#<span class="token directive keyword">include</span> <span class="token string">&lt;stdio.h&gt;</span> </span>

<span class="token comment">/* Write string copy using subscripting or indexing */</span>
<span class="token keyword">char</span> <span class="token operator">*</span><span class="token function">stringcpy1</span><span class="token punctuation">(</span><span class="token keyword">char</span> <span class="token operator">*</span>dest<span class="token punctuation">,</span> <span class="token keyword">const</span> <span class="token keyword">char</span><span class="token operator">*</span> src<span class="token punctuation">)</span> <span class="token punctuation">{</span> 
    <span class="token keyword">int</span> i <span class="token operator">=</span> <span class="token number">0</span><span class="token punctuation">;</span> 
    
    <span class="token keyword">while</span> <span class="token punctuation">(</span><span class="token punctuation">(</span>dest<span class="token punctuation">[</span>i<span class="token punctuation">]</span> <span class="token operator">=</span> src<span class="token punctuation">[</span>i<span class="token punctuation">]</span><span class="token punctuation">)</span> <span class="token operator">!=</span> <span class="token string">'\0'</span><span class="token punctuation">)</span>
        i<span class="token operator">++</span><span class="token punctuation">;</span> 
    <span class="token keyword">return</span> dest<span class="token punctuation">;</span> 
<span class="token punctuation">}</span>

<span class="token comment">/* Write string copy using pointers */</span>
<span class="token keyword">char</span><span class="token operator">*</span> <span class="token function">stringcpy2</span><span class="token punctuation">(</span><span class="token keyword">char</span> <span class="token operator">*</span>dest<span class="token punctuation">,</span> <span class="token keyword">const</span> <span class="token keyword">char</span><span class="token operator">*</span> src<span class="token punctuation">)</span> <span class="token punctuation">{</span> 
    <span class="token keyword">const</span> <span class="token keyword">char</span> <span class="token operator">*</span>s <span class="token operator">=</span> src<span class="token punctuation">;</span>
    <span class="token keyword">char</span> <span class="token operator">*</span>t <span class="token operator">=</span> dest<span class="token punctuation">;</span>

    <span class="token keyword">while</span> <span class="token punctuation">(</span><span class="token punctuation">(</span><span class="token operator">*</span>t <span class="token operator">=</span> <span class="token operator">*</span>s<span class="token punctuation">)</span> <span class="token operator">!=</span> <span class="token string">'\0'</span><span class="token punctuation">)</span> <span class="token punctuation">{</span>
        t<span class="token operator">++</span><span class="token punctuation">;</span>
        s<span class="token operator">++</span><span class="token punctuation">;</span>
    <span class="token punctuation">}</span>
    <span class="token keyword">return</span> dest<span class="token punctuation">;</span>
<span class="token punctuation">}</span>


<span class="token comment">/* Write string copy using pointers - professional edition */</span>
<span class="token keyword">char</span> <span class="token operator">*</span><span class="token function">stringcpy3</span><span class="token punctuation">(</span><span class="token keyword">char</span> <span class="token operator">*</span>dest<span class="token punctuation">,</span> <span class="token keyword">const</span> <span class="token keyword">char</span><span class="token operator">*</span> src<span class="token punctuation">)</span> <span class="token punctuation">{</span> 
    <span class="token keyword">char</span> <span class="token operator">*</span>res <span class="token operator">=</span> dest<span class="token punctuation">;</span>
    <span class="token keyword">while</span> <span class="token punctuation">(</span><span class="token operator">*</span>dest<span class="token operator">++</span> <span class="token operator">==</span> <span class="token operator">*</span>src<span class="token punctuation">)</span>
        <span class="token punctuation">;</span> 
    <span class="token keyword">return</span> res<span class="token punctuation">;</span> 
<span class="token punctuation">}</span>

<span class="token comment">/* a one line function statement for stringcopy */</span> 
<span class="token macro property">#<span class="token directive keyword">include</span> <span class="token string">&lt;stdlib.h&gt;</span> </span>
<span class="token macro property">#<span class="token directive keyword">include</span> <span class="token string">&lt;string.h&gt;</span></span>
<span class="token keyword">char</span> <span class="token operator">*</span><span class="token function">stringcpy4</span><span class="token punctuation">(</span><span class="token keyword">char</span> <span class="token operator">*</span>dest<span class="token punctuation">,</span> <span class="token keyword">const</span> <span class="token keyword">char</span><span class="token operator">*</span> src<span class="token punctuation">)</span> <span class="token punctuation">{</span> 
    <span class="token keyword">return</span> <span class="token function">memcpy</span><span class="token punctuation">(</span>dest<span class="token punctuation">,</span> src<span class="token punctuation">,</span> <span class="token function">strlen</span><span class="token punctuation">(</span>src<span class="token punctuation">)</span><span class="token punctuation">)</span><span class="token punctuation">;</span> 
<span class="token punctuation">}</span>


<span class="token keyword">int</span> <span class="token function">main</span> <span class="token punctuation">(</span><span class="token punctuation">)</span> <span class="token punctuation">{</span> 
    <span class="token keyword">char</span> destination<span class="token punctuation">[</span><span class="token number">30</span><span class="token punctuation">]</span><span class="token punctuation">;</span> 
    <span class="token keyword">char</span> source<span class="token punctuation">[</span><span class="token number">30</span><span class="token punctuation">]</span><span class="token punctuation">;</span> 
    <span class="token function">scanf</span><span class="token punctuation">(</span><span class="token string">"%[^0123456789]"</span><span class="token punctuation">,</span> source<span class="token punctuation">)</span><span class="token punctuation">;</span>
    
    <span class="token function">printf</span><span class="token punctuation">(</span><span class="token string">"%s\n"</span><span class="token punctuation">,</span> <span class="token function">stringcpy1</span><span class="token punctuation">(</span>destination<span class="token punctuation">,</span> source<span class="token punctuation">)</span><span class="token punctuation">)</span><span class="token punctuation">;</span> 
    <span class="token function">printf</span><span class="token punctuation">(</span><span class="token string">"%s\n"</span><span class="token punctuation">,</span> <span class="token function">stringcpy2</span><span class="token punctuation">(</span>destination<span class="token punctuation">,</span> source<span class="token punctuation">)</span><span class="token punctuation">)</span><span class="token punctuation">;</span> 
    <span class="token function">printf</span><span class="token punctuation">(</span><span class="token string">"%s\n"</span><span class="token punctuation">,</span> <span class="token function">stringcpy3</span><span class="token punctuation">(</span>destination<span class="token punctuation">,</span> source<span class="token punctuation">)</span><span class="token punctuation">)</span><span class="token punctuation">;</span> 
    <span class="token function">printf</span><span class="token punctuation">(</span><span class="token string">"%s\n"</span><span class="token punctuation">,</span> <span class="token function">stringcpy4</span><span class="token punctuation">(</span>destination<span class="token punctuation">,</span> source<span class="token punctuation">)</span><span class="token punctuation">)</span><span class="token punctuation">;</span> 

    <span class="token keyword">return</span> <span class="token number">0</span><span class="token punctuation">;</span>
<span class="token punctuation">}</span>

</code></pre>

