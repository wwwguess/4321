//ROOM:/d/suzhou/whci.c
//by dwolf
//97.11.7 
         
#include <ansi.h>
inherit ROOM;          

void create()
{                           
	set("short", RED"������"NOR);
	set("long", @LONG
        	 �������¹����ɵ����ã����ɱ��������������������ں�����
���ߣ�������ȴ�������ݡ�˭Ҳ��֪��Ϊʲô������������������ŮŮ����������λ
����Ӣ�ۡ���Ҳ��Ҳ�ø�����ͷ(ketou)��
LONG
	);                                        
	set("exits", ([
		"west" : __DIR__"nroad1", 
]));             
	set("objects", ([
		__DIR__"npc/girl.c" : 1,    
		__DIR__"npc/woman.c" : 1,
]));
	setup();
}             

void init()
{
	add_action("do_ketou", "ketou");
}
int do_ketou(string arg) 
{
        object me;
        object obj;
        object ob;
        me=this_player();
        
        if ( ((int)me->query("force") < 500) ||
             ((int)me->query("score") < 100000) ||
             ((int)me->query("force_factor") < 50 ) )
	     { 
             		tell_object(me, "�㹧�������ؿ���һ��ͷ��\n"); 
			//me->add("chao_ting", 1);
			me->receive_damage("gin", 5);
                return 1;
             }

        else if( ((int)me->query("gin") < 60))
             {
			tell_object(me, "�������Щ���ˣ�����ͷ��\n");  
              return 1;
             }
 
        me->receive_damage("gin",20);
        me->receive_damage("kee",10);
        message_vision("$N����ͷ������·���һ�¡�\n",me);
        
        if ( random(3) == 0 ) {
                message_vision("����ͻȻ����,$N�ӵ��˽�ȥ\n",me);
                this_player()->move(__DIR__"mishi");
                tell_room(__DIR__"mishi","����¶��΢��,�㿴�����Ϸ·��б��顣\n");
                return(1);
        }
        return(1);  
}
