// tiger.c
inherit NPC;

void create()
{
        set_name("�����׶���", ({ "tiger" }) );
        set("race", "Ұ��");
        set("age", 30);
        set("long", @LONG
����һֻ�����׶��棬��Ƶ�ëƤ�����źں�ɫ�İ��ƣ���ͷ��һƬ����
��Լ��һ��������֣�տ��ɫ���۾���б�Ϸ���������ɢ�������͵Ĺ�â��
LONG
);

        set("attitude", "aggressive");

        set("kee", 1000);
        set("max_kee", 1000);
                
        set("gin", 1000);
        set("max_gin", 1000);
        set("sen", 1000);
	set("max_sen", 1000);
        
        set("combat_exp", 1000000);
        set("limbs", ({ "ͷ��", "����", "β��","ǰ��", "���"}) );
        set("verbs", ({ "bite","claw" }) );
	set("str",30);
	set("cor",30);
	set("corpse_ob", "/d/hua/obj/dead_tiger");
	set("chat_chance", 80);
	set("chat_msg_combat", ({
		"�ϻ�һ����Х��������!\n",
		"�ϻ�β���͵�һ˦�������һ��žž����!\n",
	}));
	set("marks/��Ƥ", 1);        
        set_temp("apply/attack", 20);
	set_temp("apply/damage", 10);
	set_temp("apply/armor", 5);
        setup();
}

            
