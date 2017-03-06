// Room: /d/village/melonfarm.c

inherit ROOM;

int do_pick (string arg);

void create()
{
	set("short", "�ϵ�");
	set("long", @LONG
����һƬ�ܴ�����ϵأ�ɳ�ʵ��������ֳ����ĹϿ϶���������ɰȿ��
��͸�˵�����(melon)����ϵ��ѿ����͵�����ȥժ(pick)�ء���������ũ
�����Ӿ��ڹϵص����棬���ľ����Կ��Ǻܸ�ѽ�������Ǵ����С·��
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"melonguard",
  "northup" : __DIR__"road4",
]));

	set("no_clean_up", 0);

	setup();
}

void init()
{
	add_action ("do_pick", "pick");
}

int do_pick (string arg) 
{
 	object ob;
	object room;
	object me;
	object melon;

	me=this_player();

	room = find_object("/d/village/melonguard");
	if (arg == "melon" || arg == "��") {
	  if( random(me->query("kar"))>random(30) )
	  {
	    message_vision("$N������ȥ�������ҵ���һ����͸�˵Ĵ����ϱ��ڻ��С�\n",me );
	    melon = new(__DIR__"obj/melon");
	    melon->move(me);
	    if( objectp(room) && objectp(ob=present("meloner",room)))
	    {
	      if( random(me->query("kar"))>random(10) )
	      {
	        message_vision( "��⣬��ũ������$N͵�ϣ�����߳������\n", me );
		ob->move(__DIR__"melonfarm");
		ob->set_temp("melon/catch_thief",1);
		me->set_temp("melon/catch_thief",1);
		ob->set_leader(me);
		ob->kill_ob(me);
		//me->kill_ok(ob);
		return 1; 
	      }
	      else {
		message_vision( "��ũ�ƺ����ڴ��˯��û�з���$N��С������\n", me );
		return 1;
	      } 
	    }
	    else{
	      message_vision( "$N�����ˣ���ũû���ڹ��￴�ϡ�\n", me );
	      return 1; 
	    }
	  }
          else {
	    message_vision( "$N������ȥ�����ڻ���û�ҵ���͸�����ϡ�\n", me );
	    return 1;
	  }
	}

	return notify_fail("��Ҫժʲô��\n");

}

int valid_leave(object me,string dir)
{
	if( dir=="northup" || dir=="south" )
	  if( me->query_temp("melon/catch_thief") )
	    return notify_fail( "���ȥ·����ũ��ס�ˡ�\n" );
	return ::valid_leave(me,dir);
}
