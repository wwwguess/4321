// Room: /d/shaolin/chufang2.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "����");
	set("long", @LONG
�����ǼּҰ����̵ĳ����������ܴ��������Ҳ���.��Ӭ�����.
��ͷ���ڱ��ף�һ�����̴�ֱͨ���ݶ��������ıڱ������̻�Ѭ��
���ڣ�������Ҳ�ǽ��ڽ��ڵ�.���Ϲ��ﻹƮ��ֻ������,��������
��,��������.   ���ߵ�ǽ�Ұ�����һ�飬¶��Ȯ�������ש������
�ݽǱ��и���(dong)��
LONG
	); 
        set("objects", ([
                
                __DIR__"obj/rou.c" : 2,     
        ]));


	set("exits", ([
		"south" : __DIR__"jjbz",
	]));

	set("item_desc",([
		"brick"	: "��...��...��...��...��\n",
		"dong"	: "ǽ�Ǳ��ǿ��˸��󶴣�����ڳ����ģ���֪ͨ�����\n"
	])); 


 }

 void init()
 {
        add_action("do_enter", "enter");
        add_action("do_enter", "zuan");
 }

 int do_enter(string arg)
 {
	object me;
	mapping fam;

	me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg=="dong" )
	{
		if( (fam = me->query("family")) && fam["family_name"] == "ؤ��" ) 
		{
			message("vision",
				me->name() + "����ؤ�����ǹ���һ�������������˽�ȥ��\n",
				environment(me), ({me}) );
			me->move("/d/gaibang/jingch");
                	message("vision",
				me->name() + "�Ӷ������˽�����\n",
                		environment(me), ({me}) );
			return 1;
		}
		else 
			return notify_fail("��ôС�Ķ�������ý�ȥ��\n");
	}
}	



