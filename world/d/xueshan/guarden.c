//by dwolf
//97.11.9

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", GRN"ǰԺ"NOR);
	set("long", @LONG
	  ����ɽׯ��ǰԺ�����˸����滨��ݣ���������÷����ֵ��������
��÷һ�굽ͷ�ܿ��ţ���÷��������Щ��֡�Ժ���м��������������졣���Ǵ��úܺã�����ȥҲ�ܿ���
�����Ǻ���������ʲô������ͨ���������ǰ��������Ժ���š�
LONG
	);  
	set("exits", ([
		"south" : __DIR__"door.c",
		"north" : __DIR__"ting.c",
	]));                   
	set("objects", ([
		__DIR__"npc/guard2" : 2,
	]));
	setup();
}               
   
int valid_leave(object me,string dir)
{               
	object ob;     

	if( present("guard", environment(me)) )
    	{
        	if ( dir=="north" && !(int)me->query("mark/����") ) 
	        	return notify_fail("��Ժ������ס����,����û���±��ȥ��������ׯ����\n");
	
		tell_room(__DIR__"guarden", YEL"��Ժ����С�ֵ��������ׯ��������Ժʱ�ɽ�һ����\n\n"NOR);   
      
  /*      if ( me->query("mark/����") )
	me->delete("mark/����");          */
    }
    return ::valid_leave(me,dir);
}

void init()
{
	add_action("do_search", "search");
}

int do_search(string arg)
{
        object me,obj,ob;
     
        if ( !arg || arg != "��÷��" )
                return notify_fail("��Ҫ��ʲ��?\n");
        
        me=this_player();
		       
        if ( (int)me->query("combat_exp") <500000) {
                tell_object(me, "��ʲôҲû�ѵ���\n");
                return 1;
        }

        else if( ((int)me->query("kee")<600))
             {
	tell_object(me, "��������̫��ร�\n"); 
   		return 1;
             }
	me->receive_damage("gin",20);
        me->receive_damage("kee",60);
        message_vision("$N��ϸ������÷���š�\n",me);
        
        if ( random(3) == 0 ) {
                message_vision("�ѵ�һ�ѱ�����\n",me);
   		ob = new(__DIR__"npc/obj/coldb");
		if(ob)
                  ob->move(me);            
                else
                   printf("error\n");
                return(1);
        }
        return(1);
}
        
