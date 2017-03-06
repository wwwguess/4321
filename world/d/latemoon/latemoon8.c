#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short","����");
	set("long", @LONG
����һ�����ҡ������������Ժϵش����Ĵ���ʯ�������ܹ���һ
Щ����������ǽ��д��ټ��� �� �� ���֣� �ذ�����Լ����һ����
�����ͼ�����뻭�����ǣ��˸�����ֱ��ǣ�Ǭ���������㿲�ޡ���
���ࡣǽ�ϻ�������������Ů��Ȼ������������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
    "north" :__DIR__"latemoon7",
]));

    create_door("north","ʯ��","south", DOOR_CLOSED);
	setup();
}

void init()
{
         add_action("do_dancing", "dancing");
	 add_action("do_search" , "search");
}

int do_dancing(string arg)
{
     object me;
      me = this_player();

      if( (string)me->query("gender") == "����" ) {
      if ( (int)me->query("sen") < 100 )
           return notify_fail("�����ڵ���̫���ˣ��޷�רע�����貽��\n");
           me->receive_damage("sen", 50);
      }
      if( (string)me->query("gender") == "Ů��" ) {
      if ( (int)me->query("sen") < 50 )
           return notify_fail("�����ڵ���̫���ˣ��޷�רע�����貽��\n");
           me->receive_damage("sen", 30);
      }

        if( !arg || (arg!= "out" && arg!="yu-fong") )
             return notify_fail("�����������������������ƺ�����Ҫ�죡\n");

       if ( arg=="yu-fong" ) {
                
message_vision("$N����������������..һ��"+HIM"�� �з����� ��"+NOR"ͻȻ...\n",
                        this_player() );
         this_player()->receive_damage("sen", 50);
         this_player()->move(__DIR__"miroom");
        } else  if ( arg=="out" ) {
          message_vision("$N����������������..һ��"+HIM"�� �������� ��"+
          NOR"ͻȻ...\n",
                        this_player() );
         this_player()->move(__DIR__"bamboo");
        }

         return 1;
}

int do_search(string arg)
{
	object obj;
	if ( !arg || arg != "bed" ) {
		write("��Ҫ��ʲô��\n");
		return 1 ;
	}
	if ( !this_player()->query("mark/dance-book") ) {
	message_vision("$N��ʯ���������˺ܾã����һ������\n",this_player());
	return 1 ;
	}	
	message_vision("$N��ʯ�������ҵ���һ�������ף�\n",this_player());
	obj = new(__DIR__"obj/book");
	obj->move(this_player());
	this_player()->delete("mark/dance-book");
	return 1 ;
}
		
