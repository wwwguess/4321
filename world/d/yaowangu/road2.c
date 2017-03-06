//by dwolf

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ѩɽС��");
	set("long", @LONG
	  �����ھ��׵�ɽ���ϣ��е�һ���������ġ����̲�ס������Ц������
"���������������� "�����������ѩ������Ͽ�ֹͣ��Ц�������ľïʢ����ʯ
����������ɽ������������(vine)�������ƺ���ʲô�� ͷ�ϵ�ѩ�嶥���ƺ���һ
���׵�һ�����㻳���Լ��۾����ˡ�
LONG
	); 
	set("item_desc", ([
		"vine":
			"������������⡣���������ƿ�(push)����.\n",
	]));
	set("exits", ([
		"southdown" : __DIR__"road1.c",
	])); 
	setup();
} 

void init()
{
	add_action("do_push", "push");          
	add_action("do_climb", "climb");
}
int do_push(string arg)
{
	if ( !arg || arg!="vine" ) 
		return notify_fail("��Ҫ��ʲô��\n");
	message_vision("$N���ֲ���������\n\n",
		 this_player());
	tell_room(__DIR__"door.c",this_player()->query("name") + "�����漷�˽���.\n");   
	this_player()->move(__DIR__"door.c");
	return 1;                   
}                        

int do_climb(string arg)
{             
        object me;
        object obj;
        object ob;
        ob = this_player();
        
        if ( !arg || arg != "ѩ��" )
                return notify_fail("��Ҫ��ʲ��?\n");
        
        me=this_player();
        
        if ( ((int)me->query_skill("dodge") < 150) ) { 
                tell_object(me, "���Ṧ̫�ͣ�������ȥ��\n");
                return 1;
        }

        else if( ((int)me->query("kee")<1000))
             {tell_object(me, "��������̫��ร�\n");  
                return 1;
             }
 
        me->receive_damage("gin",50);
        me->receive_damage("kee",100);
        message_vision("$N�ֽŲ��ã���������������\n",me);
        
        if ( random(3) == 0 ) {
                message_vision("$N����������ȥ��\n",me);
                this_player()->move(__DIR__"hill2");
                message("vision","$N��ǰ��һ�����ӡ�n",
        environment(me),me);
                tell_room(__DIR__"hill2","$N������ѩ�塣\n",me);
                return(1);
        }
        return(1);
}
  


                                                
