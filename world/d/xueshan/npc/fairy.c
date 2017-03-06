//magic fairy
//by tlang

#include <ansi.h>
inherit NPC;
             
void create()   
{
	set_name(MAG"警幻仙子"NOR, ({"magic fairy", "fairy"}));
        set("gender", "女性");
	set("age", 20);
	set("per", 50);
	set("long", "幻亦是真，真亦是幻，幻不是真，真不是幻。似幻似真，似真似幻.是真是幻，仙子示之。\n");
        
	set("combat_exp", 9999999);

	setup();
}

void init()
{       
        object me; 
        me=this_player();

        ::init();
        remove_call_out("greeting"); 
        call_out("greeting", 1, me);    
        add_action("do_regret", "regret");
}
void greeting(object me)
{
        if( !me || environment(me) != environment()) return; 
        command("say 你找到这儿，是有什么后悔的事吗？\n"); 
}

int do_regret(string arg)
{                 
        object ob,me;
        me = this_player();

        if( !arg || arg=="" ) 	return 0;     
	
        if( arg=="美容" && me->query("mark/美容") ) 
        {                             	
                command("sigh");
                command("say 药王这小子又随便给人美容了，来，我给你加上经验吧。\n");
                me->add("combat_exp", 10000);
                message_vision("只见一团亮光包住$N,然后只听见仙子说:道行了，光消失了，仙子也不见了。\n",me);
                me->set("mark/恢复美容", 1);
		me->set("mark/美容", 0);
		destruct(this_object()); 
		         return 1;      
        }            
	    if( arg=="健美" && me->query("mark/健美") ) 
        {                             	
                command("sigh");
                command("say 药王这小子又随便给人健美了，来，我给你加上经验吧。\n");
                me->add("combat_exp", 15000);
                message_vision("只见一团亮光包住$N,然后只听见仙子说:道行了，光消失了，仙子也不见了。\n",me);
                me->set("mark/恢复健美", 1);    
		me->set("mark/健美", 0);
		destruct(this_object()); 
		         return 1;      
        }            
}
                      

                                           
