
inherit NPC;

void create()
{
        set_name("��ԭ��", ({"wolf" }) );
        set("race", "Ұ��");
        set("age", 5);
        set("long", "һֻ�ײе���,����ϻ�����Ѫ��.\n");
        
        set("str",15);
        set("cor",52);
        set("cps",15);

        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" }) );
	set("max_kee",3000);
        set("attitude","aggressive");
        set("combat_exp",20000);
        set("bellicosity",3000);
       
        set_temp("apply/attack",60);
        set_temp("apply/armor",40);
        set_skill("dodge", 120);
        

        setup();
}

