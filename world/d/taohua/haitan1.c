// Room: /d/new_taohua/haitan.c

inherit ROOM;




void create()
{
	set("short", "����ͤ");
	set("long", @LONG
��ǰ��һ��ʯͤ���к���������ͤ����Զ�����沨��
������۹�ƬƬ����ʱ�к��紵���������Ŀ��������㲻
�����º�����һ���ĳ嶯��
LONG
	); 
              set("exits", ([
                "southwest" :__DIR__"taijie1",
	]));

	  setup();
}

 void init()
{       object ob;
        add_action("do_swim", "swim");
        
}

int do_swim(string arj)
{this_player()->move(__DIR__"hai");  
  return 1;
}
