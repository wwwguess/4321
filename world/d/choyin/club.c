// Room: /d/choyin/club.c
# include <room.h>
# include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ���ɰ�é�ݴ�ɵĲ��ã����ڽ���һ��齣�һ�������İ����Σ���ǰһ����Ƭװ�Ѿ�
�£�����:
                              ����δ�����Ҷ�
                              ���޲��ɶ�����
������̯�����(books)����һ֧��ɰ�ʣ�һ����⾹���������²أ������Ϻ������� 
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"yard.c",
  "east" : __DIR__"fence.c",
]));
        set("no_fight", "1");
        set("no_magic", "1");
        set("item_desc", ([
                "books" : @TEXT
���ϵ������ֶ��ţ�װ֡���ӣ������ΰ��飬���м�����ԭ�ء��㰴�಻ס����������
����(scratch)��ϸ�о�һ����
TEXT
]));     

        create_door("west", "����", "west" , DOOR_CLOSED);    
	set("no_clean_up", 0);

	setup();
}

void init()
{
   add_action("do_pray","pray");
   add_action("do_dance","dancing");
   add_action("do_scratch","scratch");
}

int do_dance(string arg)
{
     message_vision("Ҳ��֪����ʿ��ôŪ�ģ�$N�޷�����רע���貽��\n",
                this_player());   
      return 1;
}               

int do_pray(string arg)
{
     message_vision("Ҳ��֪����ʿ��ôŪ�ģ�$N��������������ˡ�\n",
                this_player());       
    return 1;
}               

int do_scratch(string arg)
{ 
  int ddt=0; 
  object book;
  object ob;

  ob = this_player();

  if( !arg || arg!="books" ) 
  return 0;
  else { ddt = ddt + 1; 
  message_vision("$N���˲�����ץ��һ������뻳�С�\n\n",
                this_player()); 

  switch( random(3) ) {
                case 0: book = new("/d/choyin/npc/obj/book1");
                        book ->move(ob);
                        ob->set_temp("choyin/��", ddt); 
                        break;
                case 1: book = new("/d/choyin/npc/obj/book1");
                        book ->move(ob);
                        ob->set_temp("choyin/��", ddt); 
                        break;
                case 2: book =new("/d/choyin/npc/obj/book2");
                        book ->move(ob);
                        ob->set_temp("choyin/��", ddt); 
                        break; 
                      }
}
  return 1;
}


int valid_leave(object me, string dir)
{       string item;
        object obj;

        item = "book";
        if( !objectp(obj = present(item, me)) )  {
                tell_object(me, "���뿪����!\n" NOR );
        }  else  {
            while(objectp(obj = present(item, me)) ) 
              { if ( me->query_temp("choyin/��") ) {
                tell_object(me, HIC "�㽫��Żص�������\n" NOR);
                obj = present(item, me); 
                destruct(obj);
                                                         }
           me->set_temp("choyin/\112\151", 0);   
              }        
                 }
        return 1;
} 
