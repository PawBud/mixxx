#include "waveform/widgets/allshader/filteredwaveformwidget.h"

#include "waveform/renderers/allshader/waveformrenderbackground.h"
#include "waveform/renderers/allshader/waveformrenderbeat.h"
#include "waveform/renderers/allshader/waveformrendererendoftrack.h"
#include "waveform/renderers/allshader/waveformrendererfiltered.h"
#include "waveform/renderers/allshader/waveformrendererpreroll.h"
#include "waveform/renderers/allshader/waveformrenderersignalbase.h"
#include "waveform/renderers/allshader/waveformrenderertextured.h"
#include "waveform/renderers/allshader/waveformrendermark.h"
#include "waveform/renderers/allshader/waveformrendermarkrange.h"
#include "waveform/widgets/allshader/moc_filteredwaveformwidget.cpp"

namespace allshader {

FilteredWaveformWidget::FilteredWaveformWidget(const QString& group,
        QWidget* parent,
        WaveformRendererSignalBase::Options options)
        : WaveformWidget(group, parent) {
    addRenderer<WaveformRenderBackground>();
    addRenderer<WaveformRendererEndOfTrack>();
    addRenderer<WaveformRendererPreroll>();
    addRenderer<WaveformRenderMarkRange>();
    if (options & allshader::WaveformRendererSignalBase::HighDetail) {
        addRenderer<WaveformRendererTextured>(::WaveformWidgetType::Filtered);
    } else {
        addRenderer<WaveformRendererFiltered>(false);
    }
    addRenderer<WaveformRenderBeat>();
    addRenderer<WaveformRenderMark>();

    m_initSuccess = init();
}

void FilteredWaveformWidget::castToQWidget() {
    m_widget = this;
}

void FilteredWaveformWidget::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);
}

} // namespace allshader
