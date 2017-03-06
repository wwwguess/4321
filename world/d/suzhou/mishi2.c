//ROOM:/d/suzhou/mishi2.c
//by dwolf
//97.11.7              

#include <ansi.h>
inherit ROOM;          

void create()
{                           
	set("short", RED"����������"NOR);
	set("long", @LONG
          �������������ֻ�����ܵ�����������ѣ�һͰͰ���͹������棬��Щ
����Ѳ�֪�����˶������ˡ�ʯ�ҵĵذ����б��飬���Ϲ���һ�ѱ���(ywsword)��
LONG
	);                                        

	set("objects", ([
		"/d/hangzhou/npc/obj/wmbook1" : 1,    
]));                         

	setup();
}      

void init()
{
	add_action("do_qu", "qu");
	add_action("do_swear", "swear");
}
               
int do_qu(string arg)
{
        object me;
	object ob;
	me = this_player();
        
        if ( !arg || arg != "ywsword" )
                return notify_fail("��Ҫ��ʲ��?\n");  
	
	if(query_temp("mark/been_get")) 
		return notify_fail("�����ѱ������ˡ�\n");
                       
        if ( ((int)me->query_skill("dodge") < 100) ) { 
                tell_object(me, "���Ṧ̫�ͣ��β�������\n");
                return 1;
        }

        else if( ((int)me->query("kee")<500))
             {tell_object(me, "��������̫��ร�\n");  
              return 1;
             }
 
        me->receive_damage("gin",50);
        me->receive_damage("kee",50);
        message_vision("$N�ż��أ�����һ�ݣ���Ҫȡ������\n",me);
        
        if ( random(3) == 0 ) {
                message_vision("$N�ѱ���ȡ��������\n",me); 
		ob = new(__DIR__"npc/obj/ywsword");
                ob->move(this_player());   
		me->set("marks/ywsword",1);
                set_temp("mark/been_get",1);
	     return(1);
        }
        return(1);
}        
                                     
int do_swear(string arg)
{                 
	object ob,me;
	me = this_player();

	if( !arg || arg=="" ) return 0;    

        if( arg=="�Ҿ�"
	||  arg=="���ڻʵ�") 
	{
		command("haha");
		message("vision", YEL"���д���һ���Ц�������ú��ӣ��������׻������\n"NOR, me);
		me->move("/d/suzhou/whci");
		tell_room(__DIR__"whci", YEL"$N��Ȼ���������\n"NOR); 
		return 1;      
	}
}
                                                





