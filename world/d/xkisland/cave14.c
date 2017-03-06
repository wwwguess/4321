// Room: /u/dunno/cave/cave14.c
// /u/dan/room/cave/cave14.c
// dan
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
ǧ��Ŷ�,�Ĵ������������.�ı��Ѿ��߲߰���,��ϡ�ɼ���
Щ�Ѻ���.ǽ���������Ͳʻ���һЩ�ֻ�.�ı�ȼ�ž���,��������
����,���ڶ�һ��,��һ������Щ��������. ǽ���ϵ��־���ϸ����
�ǣ��� ������Ϊ�ᡣ
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"cave13",
  "south" : __DIR__"cave15",
]));
	set("objects", ([ /* sizeof() == 1 */
    __DIR__"npc/npc15":1,
    ]));
	set("no_fight", 1); 
        set("no_sleep_room",1);
        setup();
}
  
void init()
{
	add_action("do_studywall", "studywall");
}

int do_studywall()
{
	object me;
        me = this_player();
	message_vision("$Nר�ĵ��о�ǽ���ϵ�ͼ�Ρ�\n", me); 
        if ((int)me->query_skill("literate", 1) >= 1)  
                  {
                       tell_object(me, "���ƺ���������Щͼ��!\n");
                  }
        if ((int)me->query_skill("literate", 1) <= 0)
                 {
                       tell_object(me, "�㷢����Щͼ���ƺ����书�й�!\n");
                  }
         if ((int)me->query_skill("cuff", 1) <= 99
         && (int)me->query_skill("literate", 1) <= 0
               ) 
                {
                        tell_object(me, "��Щ��������˵̫���ˣ�����\n");
                 }
        if ((int)me->query_skill("cuff", 1) >= 150
         && (int)me->query_skill("literate", 1) <= 0
               ) 
                {
                        tell_object(me, "��Щ��������˵̫ǳ�ˣ�����\n");
                 }
        if ((int)me->query_skill("cuff", 1) <= 149
         && (int)me->query_skill("cuff", 1) >= 100 
         && (int)me->query_skill("literate", 1) <= 0 
               )       
        	{       if( pow(to_float((int)me->query_skill("cuff", 1)), 3.0) / 10.0 >to_float(me->query("combat_exp")) )
                        return notify_fail("�㾭�鲻�㣬��ȥ����.\n");
	        	me->receive_damage("gin", 20);
	        	me->improve_skill("cuff", (me->query("int")));
		        tell_object(me, "��Ļ���ȭ��������ߣ�����\n");
	        }

	return 1;

}

