inherit NPC;
 
void create()
{
        set_name("����ͮ", ({ "eton","zhin" }) );
        set("gender", "Ů��" );
        set("age", 27);
        set("long", @TEXT
����ɫ���㣬�������ף�����浾��������御�
��ϧü������һ����ɷ�Ƹɷ��϶�����Ҫ����
ȾѪ���ƽ����֡�
TEXT
);
       set("class", "dancer");
       set("combat_exp", 70000);
        set_skill("unarmed", 50);
        set_skill("dodge", 40);
        set_skill("stormdance", 50);
        set_skill("tenderzhi", 50);
        set_skill("force",50);
        map_skill("dodge","stormdance");
        map_skill("unarmed","tenderzhi");
        set("force", 1000);
        set("max_force", 500);

        create_family("����ׯ",3,"����");
        setup();
        carry_object("/d/latemoon/obj/deer_boot")->wear();
        carry_object("/d/latemoon/obj/necklace");
}

