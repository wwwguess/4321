// Room: gold


inherit ROOM;
#include <room.h>

void create()
{
	set("short", "�ر���");
	set("long", @LONG 
����ǽ�ھ����������ɣ������������һ�鼫�����ڡ�
�����б��ϰ�ͷ���������������챦����һ��������������������֮���ľ�Ʒ,
����һ������Ƕ���鱦�ĳ����Ѿ����ʣ����⾧Ө��Ŀ�����ɷ��
LONG
        );
         
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"gu5",
	]));
         
    set("item_desc", ([
                "sword": "
��һ������һ�Ѽ�ֵ���ǵı�������������ġ�\n",
                "����": "
��һ������һ�Ѽ�ֵ���ǵı�������������ġ�\n",
		"���": "
һ���龧Ө�����񣬷·𾭳��������ִ����� \n", 
                "jade": "
һ���龧Ө�����񣬷·𾭳��������ִ����� \n",
    ]) );
    setup();
      
}
 
 void init()
{
   add_action("do_open","push"); 
   
   add_action("do_get","pick");
}

         


int do_open(string arg)
{
    object me;  
	me=this_player();
	switch (arg)
         {
         case "jade":
         case "���":
             if(query("exits/girl")) return notify_fail("���Ѿ��ǿ�����");
             message_vision("$N�����������һ��������ϳ���һ��С��\n",this_player());
             set("exits/enter",__DIR__"girlroom");
             return 1;
         }
//        default: return notify_fail("��Ҫ��ʲô��\n");
	 
}

int do_get(string arg)
{
    object swo;
	if( query_temp("mark/been_get")) return notify_fail("���ѱ������ˡ�\n");
        if(random(this_player()->query("kar")) > 19 && random(100)>90) 
        { 
		swo=new(__DIR__"obj/leavehook");
		swo->move(this_player());
		set_temp("mark/been_get",1);
		write("���ǽ�ϰ�����һ����𹳡�\n" );
	}
	else
        { 
		write("������ȥ�ν���ȴ���������ˡ�\n");
        	this_player()->receive_damage("kee",50);
	}
        
        return 1;

}
void reset()
{
    ::reset();
	delete_temp("mark/been_get");
    if(query("exits/enter"))
    	delete("exits/enter");
}