// shagu.c ɵ��
//by yuer
inherit NPC;

void create()
{
        set_name("ɵ��", ({ "sha gu", "sha", "gu" }));
        set("long", "��һ��ɵͷɵ�Ե����ӣ�������ɵɵ��Ц�š�\n");
        set("title", "�һ�������");
        set("gender", "Ů��");
        set("age", 25);

        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set_temp("apply/damage", 5);

        set("combat_exp", 20000);
        set("shen_type", 1);
        setup();



}
