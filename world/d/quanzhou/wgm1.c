// room: wgm1.c
// Jay 9/9/97
//write by lysh
#include <room.h>
#include <ansi.h>

inherit ROOM;
//inherit F_CLEAN_UP;
int destmu();

void create()
{
    set("short", "Ȫ�����");
    set("long", @LONG 
    �����Ǿ������Ȫ�ݷֹݣ����Ϻ������˵ط���һЩʯ����ʯ�ģ�
ǽ������һЩľ׮����������������������������������ǽ�Ϲ���
һ������(paizi)��
LONG
    );
    set("item_desc", ([
		"paizi" : "�������ʱ�ر� \n"
                        "\n               Ȫ�ݷֹ���\n"
        ]));

    set("exits", ([
//	"north" : __DIR__"wg1",
	"south" : __DIR__"dongjie",
    ])); 
            set("objects",([
//		__DIR__ +"npc/wangerm.c" : 1,
            ]));
    set("no_fight",1);
    set("no_steal",1);
    set("no_sleep_room",1);
    setup();
    set("no_clean_up",1);
}
   
int valid_leave(object me,string dir)
{
  if (dir == "north" ) 
  {
  if(objectp(present("wang er ma", environment(me))))
    {  
  if(!present("wang er ma")->query_temp("����/mark"))
     {
  if( this_player()->query_temp("��Ǯ��/mark"))
      {

     write("������:С����Ͱ�ľ��׼���ã���ү�����\n");       
     this_player()->delete_temp("��Ǯ��/mark");              
     present("wang er ma")->set_temp("����/mark",1);
 //    destmu();         
     return ::valid_leave(me, dir);                           
     
      }
  else
  return notify_fail("������һ���ۣ�����ߴ���ȥ ��\n");     
       }
  else
  return notify_fail("������:�Բ��������������ˡ�\n");     
    }
  else
    me->move(__DIR__"wgn1");  
    return notify_fail("������ȥ������������ľ�˻�û��׼���á�\n");
  }
  else
  return ::valid_leave(me,dir);
}
  
int destmu()
{
	int i;
	object *inv;
	inv = all_inventory(find_object(__DIR__"wg1"));
	i = sizeof(inv);
	while(i--)
		if( !userp(inv[i]) ) destruct(inv[i]);
	return 1;
}
