// Room: /d/taohua/zhaozhe.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ǰ��������ֻ�и��Ľ�����һƬ�ںڵ�
��̶������е�ͷ���ˣ��ֲ�������·�ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"yinggu",
  "north" : "/d/wudang/tygate2",
  "east"  : __DIR__"zhaozhe",
  "west"  : __DIR__"zhaozhe",
]));                                                  
       set("item_desc", ([
                "���": "��һֻ������(kill)\n",
                "hama": "��һֻ������(kill)\n",
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
        { i=i*10-600;
        if (i<=0)
         {
	   this_player()->set_temp("noway");
           return notify_fail("���߱���̶��ס��ȥ·\n");
          }
         if ((random(i)>8) && !(this_player()->query_temp("noway")))
         { write("���˼һ��,�ҵ��˳���\n");
 	   return ::valid_leave(me, dir);
          }
         else
          {this_player()->set_temp("noway");
           return notify_fail("��������̶��ס��ȥ·\n");
          }
         }
         return ::valid_leave(me, dir);
}        


 void init()
{
        add_action("do_kill","kill");
}
int do_kill(string arg)
{ object zhi,me;
  me=this_player(); 
  if (me->query_temp("killed"))
  return notify_fail("û�и���ˡ�\n");
  
  me->set_temp("killed",1);
  zhi=new(__DIR__"npc/hama");
  zhi->move(environment(me)); 
  zhi->kill_ob(me);
  me->kill_ob(zhi);
  return 1;
