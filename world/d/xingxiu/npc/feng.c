// npc: /d/xingxiu/npc/ke.c
// Jay 3/27/96

inherit NPC;

void create()
{
        set_name("ŷ����", ({ "ouyang feng", "ouyang", "feng" }));
        set("long", "���ǰ���ɽׯ�����ųơ���������ŷ����\n");
        set("title", "�϶���");
        set("gender", "����");
        set("age", 53);

        set("attitude", "peaceful");

        set("str", 30);
        set("int", 24);
        set("con", 30);
        set("dex", 24);

        set("kee", 500);
        set("max_kee", 500);
        set("gin", 300);
        set("max_gin", 300);
        set("force", 1500);
        set("max_force", 1500);
        set("force_factor", 50);

        set("combat_exp", 1500000);
        set("score", 200000);
        set_skill("force", 200);

   // other set needed for future use.

        setup();
}
