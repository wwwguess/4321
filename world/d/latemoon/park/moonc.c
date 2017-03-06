inherit ROOM;

void create()
{
    set("short", "����");
	set("long", @LONG
����һ�����顢���ֱ���¶��ţ�������ǰ���ֵ������ɷ�ǽ��
���������ܴ��Ĵ��֡����߷ֱ����������ͨ���һ����볤��������
�����һ����������(flower)�������ע�⣬ֻ��������ɡ��˿����
�ƣ����µ�ɰ��ʮ��Ư����
LONG
	);
    set("item_desc", ([
        "flower" : @TEXT
    ����ϸ������һ����״��Щ���ص��������ģ���һ����
������������ԭ�����Ա߻���һ�䲻̫���ۣ������Գɽ��
ɫ��С������ֱ�����������ƺ���һ�����ҩ�ġ�����
����ժ��(pick)��
TEXT
    ]) );
	set("exits", ([ /* sizeof() == 2 */
      "north" :__DIR__"flower2",
      "south" :__DIR__"bridge1",
      "west" :__DIR__"moon2",
      "east" :__DIR__"moon1",

]));

    set("objects", ([
    ]) );
	setup();

}
void init()
{
            add_action("do_pick","pick");
}
void reset()
{
        ::reset();
        set("pick_available" , 2);
}
int do_pick(string arg)
{
       object me,obj;

       me = this_player();
       if( !arg || arg!="flower" )
              return notify_fail("��Ҫժȡʲô? \n");
       if ( query("pick_available") )  {
       message_vision("$N������������ժ��һ��С���\n",this_player() );
       obj = new ("/d/latemoon/park/npc/obj/flower");
       obj->move(me);
       add("pick_available", -1);
       }
       return 1;
}
