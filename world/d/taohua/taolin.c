// Room: /d/taohua/taolin.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һƬïʢ�����֣��������ܵ����źܶ����������Ͻ������һ�����ǰһ����
�ۺ���һ����۶��ǣ���о��е�ͷ���ˣ��ֲ�������·�ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"taijie1",
  "south" : __DIR__"haibian",
  "east"  : __DIR__"taolin",
  "west"  : __DIR__"taolin",
]));                                                  
       set("item_desc", ([
                "��": "���ϵ���֦����ժ(zhai)\n",
                "tree":"���ϵ���֦����ժ(zhai)\n",
           ]));
	set("no_clean_up", 0);

	setup();
	
}
int valid_leave(object me, string dir)
{          
      int i;
       
        if ((string)this_player()->query("family/family_name")!="�һ���")
          i = 0;
        else i =20;
          i = (int)this_player()->query_skill("qimen-bagua",1)+i; 
        if (dir=="north"|| dir=="n") 
        { i=i*10-290;
        if (i<=0)
         {
	   this_player()->set_temp("noway");
           return notify_fail("���߱�������ס��ȥ·\n");
          }
         if ((random(i)>8) && !(this_player()->query_temp("noway")))
         { write("���˼һ��,�ҵ��˳���\n");
 	   return ::valid_leave(me, dir);
          }
         else
          {this_player()->set_temp("noway");
           return notify_fail("���߱�������ס��ȥ·\n");
          }
         }
         return ::valid_leave(me, dir);
}        


 void init()
{
        add_action("do_zhai","zhai");
}
int do_zhai(string arg)
{ object zhi,me;
  me=this_player();
  zhi=new(__DIR__"obj/taozhi");
  zhi->move(me); 
  message_vision( "\n$N��������ժ��һ����֦��\n",this_player());  
  return 1;
}
