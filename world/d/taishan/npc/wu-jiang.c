 // bianguan-wujiang

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("�߹��佫", ({ "wu jiang", "jiang", "guard" }) );
        set("gender", "����");
        set("age", 35);
        set("long",
                "����λ�����佫�������ּף���ִ��ꪣ�˫Ŀ���⾼���������Ѳ�������ܵ����Ρ�\n");
        set("combat_exp", 300000);
        set("shen_type", 1);
        set("attitude", "heroism");

        set("str", 30);
        set("con", 25);
        set("int", 20);
        set("dex", 30);

        set("max_kee", 1000);
        set("eff_kee", 1000);
        set("kee", 1000);
        set("max_gin", 200);
        set("gin", 200);
        set("force", 1000);
        set("max_force", 1000);
        set("jiali", 60);

        set_skill("halberd", 100);
	set_skill("mo-ji-jue", 100);
	set_skill("unarmed", 100);
//	set_skill("unarmed1", 50);
        set_skill("parry", 100);
        set_skill("dodge", 100);
	set_skill("mo-shan-jue", 100);

	map_skill("halberd", "mo-ji-jue");
	map_skill("parry", "mo-ji-jue");
//	map_skill("unarmed", "unarmed1");
	map_skill("dodge", "mo-shan-jue");

        setup();

        carry_object("/obj/weapon/fangtianji")->wield();
        carry_object("/obj/cloth/tiejia")->wear();
}
