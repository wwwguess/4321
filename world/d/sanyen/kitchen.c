// Room: /d/sanyen/kitchen.c

inherit ROOM;

void create()
{
	set("short", "�����");
        set("long", @LONG
һ��������Ǭ���ĳ���, �����ߵĽ�����������������, ������
ȼ�����ܴ��, ���Ϸֱ����һ�����(pot) ��һ������(steampot)
�����Ӽ�������ð������������Լ�����, ���̲�ס�����������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
        "east" : __DIR__"corridor1",
]));

        set("item_desc", ([
            "pot": "һ��ð�����ڵ������ĺ�ɫ������, ��ͷ������С���ࡣ\n",
            "steampot": "һ�����ٱ�ɵ�����, �������ζʹ�����(open)����һ�ơ�\n"
]) );

        set("objects", ([
            __DIR__"npc/cook_bonze" : 1 ]) );
	set("no_clean_up", 0);

	setup();
}

void init()
{
   add_action("do_open", ({"open"}) );
   add_action("do_take", ({"take"}) );
}

int do_open(string arg)
{
   if (!arg||arg!="steampot")
      return notify_fail("��Ҫ��ʲô��\n");
   if (!present("cook bonze"))
      {
       message_vision("$N�������ĸ�\��, һ������ð��$N�����ϡ�\n"
                      "$N��ϸһ��, ֻ������������һ�����ְ��֣ѵĴ���ͷ(maintal)��\n",this_player());
       return 1;
      }
   else
      {
       message_vision("�շ�ɮ˵:�����ӷ� !! ʩ�������ֶ���, ����ƶɮ�󷹡�\n",
this_player());
       return 1;
      }
}

int do_take(string str)
{
   object ob;
   if (!str||str!="maintal")
       return notify_fail("��Ҫ��ʲô��\n");
   if (!present("cook bonze"))
      {
       if ((int)query("maintal_trigger")>=5)
          {
           return notify_fail("ͻȻ����������������������˵��̫��С�ĳԵ�ҭ��Ŷ!!\n");
          }
       else
          {
           message_vision("$N���������ó�һ���Ⱥ�������ͷ��\n",this_player());
           ob=new(__DIR__"npc/obj/maintal");
           ob->move(this_player());
           add("maintal_trigger",1);
           return 1;
          }
      }
   else
      {
       message_vision("�շ�ɮ˵:�����ӷ� !! ʩ��͵�����ǲ��õ���ΪŶ!!!\n",this_player());
       return 1;
      }
}

void reset()
{
        ::reset();
        delete("maintal_trigger");
}
