//ROOM:/d/suzhou/yuanlin6.c
//by dwolf
//97.11.7 
         
#include <ansi.h>
inherit ROOM;            

void create()
{                           
	set("short", RED"����԰��"NOR);
	set("long", @LONG
        	  Сͤ�ĵذ����Բ�ͬ��ɫ��ϸʯ���ɸ���ͼ����·���ͼ�����
��ȫԱ��һ�����塣��ÿ��ͼ�����ж��������ݣ��ܼƻ�ʯ��·��Լ�ж�ʮ����һ��
�����ͣ�����ʤ�ա�Сͤ�����ϵĺ�Ҷ�������ˣ�¶���峺����ˮ��ˮ���ƺ���ʲô
�ڶ���Ҳ�������Ǳ��(dive)ˮ�п�һ����
LONG
	);                                        
	set("exits", ([
		"west" : __DIR__"yuanlin4", 
]));             
	set("objects", ([
		__DIR__"npc/girl.c" : 1,
]));
	setup();
}              

void init()
{
	add_action("do_dive", "dive");
}

int do_dive(string arg) 
{
        object me;
        object obj;
        object ob;
        me=this_player();
        
        if ( ((int)me->query("kee") < 500) ||
             ((int)me->query("sen") < 300) ||
             ((int)me->query("force_factor") < 50 ) )
             { 
                        tell_object(me, "�����˻��Ǳ���ȥ�ĺá�\n"); 
                        return 1;
             }        
  	     
        me->receive_damage("kee",100);
        me->receive_damage("gin",10);
        message_vision("$Nһͷ��ˮ�����˽�ȥ��\n",me);
        
        if ( random(3) == 0 ) {
                message_vision("$N������ˮ�С�\n",me);
                me->move("/d/suzhou/shuidi");
                tell_room(__DIR__"shuidi","����¶��΢��,ˮ���ܼ���\n");
                return(1);
        }
        return(1);  
}
  

