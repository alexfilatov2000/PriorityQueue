<h1>
    Process Manager with priority queue
</h1>
<h4>Priority Queue</h4>

<div>
    Priority Queue is an extension of queue with following properties.
    <br>
    Every item has a priority associated with it.
    <br>
    An element with high priority is dequeued before an element with low priority.
    <br>
    If two elements have the same priority, they are served according to their order in the queue.
</div>
<h4>Code structure</h4>
    To complete the task my priority queue supports following operations.
    
    push(&que, item, priority): Inserts an item with given priority.
    top(&que): Returns the highest priority item.
    pop(&que): Removes the highest priority item.
    show(&que): Show all items with priority.
    orders(&que, size, from, to, Pfrom, Pto, _time): This is a service applications which show to us our orders one by one
<div>
</div>

<h4>Usage</h4>
<div>
To use the manager you need to create class pqueue que, than create function of orders and input parameters that you need it.
</div>

<h4>Examples</h4>

   Code:
  
    pqueue que;
    orders(que, 10, 0, 20, 10, 30, 1000);
    
Output:
<div>
<img src="./images/output.png">
</div>

<h4>Graphics</h4>
<div>
<img src="./images/plot1.png">
</div>

<div>
<img src="./images/plot2.png">
</div>

<div>
<img src="./images/plot3.png">
</div>

   


